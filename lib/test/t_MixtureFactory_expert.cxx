//                                               -*- C++ -*-
/**
 *  @brief The test file of class MixtureFactory
 *
 *  Copyright 2005-2018 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License.
 *
 *  This library is distributed in the hope that it will be useful
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 */
#include <cmath>
#include <openturns/OT.hxx>
#include <openturns/OTtestcode.hxx>
#include "MixtureFactory.hxx"
#include <openturns/Normal.hxx>
#include <openturns/Point.hxx>
#include <openturns/Sample.hxx>
#include <openturns/Collection.hxx>
#include <openturns/Distribution.hxx>
#include <openturns/PlatformInfo.hxx>
#include <openturns/Indices.hxx>

using namespace OTMIXMOD;

int main (int argc, char *argv[])
{
  TESTPREAMBLE;
  OT::OStream fullprint(std::cout);

  try
    {
      OT::UnsignedInteger size(200);
      OT::UnsignedInteger dim(1);

      // To extract the input part of the mixture
      OT::Indices inputIndices(dim);
      inputIndices.fill(0);
      // To extract the output part of the mixture
      OT::Indices outputIndices(dim);
      outputIndices.fill(dim);

      OT::SymbolicFunction model("x", "(1.0 + sign(x)) * cos(x) - (sign(x) - 1) * sin(2*x)");
      OT::Sample dataX(OT::Uniform().getSample(size));
      dataX = dataX.sort();
      OT::Sample dataY = model(dataX);
      // For validation
      OT::Sample dataXValid(OT::Uniform().getSample(size/5));
      OT::Sample dataYValid(model(dataXValid));

      OT::Sample data(size, 2);
      for (OT::UnsignedInteger i = 0; i < size; ++i)
        {
          data[i][0] = dataX[i][0];
          data[i][1] = dataY[i][0];
        }

      OT::ExpertMixture bestExpert;
      OT::UnsignedInteger bestCluster(0);
      OT::Scalar bestError(OT::SpecFunc::MaxScalar);
      OT::UnsignedInteger k(2);
      OT::UnsignedInteger kmax(10);
      OT::Bool stop(false);

      Gaussian_pk_Lk_C covModel;
      while (!stop)
        {
          fullprint << "Try with " << k << " cluster(s)" << std::endl;
          OT::Point logLike(0);
          OT::Indices labels(0);

          // Classify data
          OT::Mixture mixture(MixtureFactory(k, covModel).buildAsMixture(data, labels, logLike));

          // Build the clusters
          fullprint << "Build the clusters" << std::endl;
	  OT::Collection<OT::Sample> clusters(MixtureFactory::BuildClusters(data, labels, k));

          // Build the local meta-models
          fullprint << "Build the local experts" << std::endl;
          OT::Basis metaModels;
          for (OT::UnsignedInteger i = 0; i < k; ++i)
            {
              // Extract the distribution of the current cluster
              OT::Distribution distribution(mixture.getDistributionCollection()[i].getMarginal(inputIndices));
              // Build the local meta model using PCE
              // We use a projection strategy
              OT::ProjectionStrategy projection = OT::LeastSquaresStrategy(distribution);
              // We use an Hermite chaos expansion
              OT::OrthogonalProductPolynomialFactory basis(OT::Collection<OT::OrthogonalUniVariatePolynomialFamily>(dim, OT::OrthogonalUniVariatePolynomialFamily(OT::HermiteFactory())));
              // FixedStrategy
	      OT::UnsignedInteger degree;
              if (k == 1) degree = 16;
              else degree = 2;
              OT::AdaptiveStrategy adaptive(OT::OrthogonalBasis(basis), OT::EnumerateFunction().getStrataCumulatedCardinal(degree));
              OT::FunctionalChaosAlgorithm algo(clusters[i].getMarginal(inputIndices), clusters[i].getMarginal(outputIndices), distribution, adaptive, projection);
              algo.run();
              metaModels.add(algo.getResult().getMetaModel());
            }
          fullprint << "Build the expert mixture" << std::endl;
          OT::MixtureClassifier classifier(mixture);
          OT::ExpertMixture expert(metaModels, classifier);
          fullprint << "Value at -1=" << expert(OT::Point(1, -1.0))[0] << std::endl;
          fullprint << "Value at  0=" << expert(OT::Point(1, 0.0))[0] << std::endl;
          fullprint << "Value at  1=" << expert(OT::Point(1, 1.0))[0] << std::endl;
          // Validation error
          fullprint << "Validation" << std::endl;
          fullprint << "expert input dimension=" << expert.getInputDimension() << std::endl;
          fullprint << "validation dimension=" << dataXValid.getDimension() << std::endl;
          OT::Sample dataYMeta(expert(dataXValid));
          OT::Scalar error(0.0);
          for (OT::UnsignedInteger i = 0; i < dataYMeta.getSize(); ++i)
            error += (dataYValid[i] - dataYMeta[i]).normSquare();
          fullprint << "k=" << k << " error=" << error << std::endl;
          if (error < bestError)
            {
              bestExpert = expert;
              bestCluster = k;
              bestError = error;
            }

          stop = (k == kmax);
          fullprint << k << " cluster(s) done, best=" << bestCluster << " error=" << bestError << std::endl;
          k += 1;
        }
    }
  catch (OT::Test::TestFailed & ex)
    {
      std::cerr << ex << std::endl;
      return OT::Test::ExitCode::Error;
    }

  return OT::Test::ExitCode::Success;

}
