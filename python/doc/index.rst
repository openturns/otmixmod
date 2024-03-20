otmixmod documentation
========================

The Mixmod (MIXture MODelling) library (https://github.com/mixmod) and executable provide efficient algorithms for density estimation, clustering or discriminant analysis problems.

The probability density function of a mixture is a weighted sum of densities:

.. math::

   \begin{align*}
      f(x) & = \sum_i \alpha_i p_i(x)  & \sum_i \alpha_i & = 1 \quad \text{with~} 0 \leq \alpha_i \leq 1
   \end{align*}

MIXMOD estimates the mixture parameters through maximum likelihood via the EM (Expectation Maximization, Dempster et al. 1977), and the SEM (Stochastic EM, Celeux and Diebolt 1985) algorithm or through classification maximum likelihood via the CEM algorithm (Clustering EM , Celeux and Govaert 1992). 

User documentation
------------------

.. toctree::
   :maxdepth: 2

   user_manual/user_manual
   ../auto_examples/index.rst

Indices and tables
==================

* :ref:`genindex`
* :ref:`search`

