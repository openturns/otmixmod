# norootforbuild
%global python_sitearch %{_libdir}/python%(python3 -c "import sysconfig; print(sysconfig.get_python_version())")/site-packages

Name:           otmixmod
Version:        0.20
Release:        0%{?dist}
Summary:        OpenTURNS module
Group:          System Environment/Libraries
License:        GPLv3+
URL:            http://www.openturns.org/
Source0:        http://downloads.sourceforge.net/openturns-modules/otmixmod/otmixmod-%{version}.tar.bz2
BuildRequires:  gcc-c++, cmake, swig
BuildRequires:  openturns-devel
BuildRequires:  python3-openturns
BuildRequires:  python3-devel
BuildRequires:  mixmod-devel
Requires:       libotmixmod0

%description
Template module for OpenTURNS library.

%package -n libotmixmod0
Summary:        otmixmod development files
Group:          Development/Libraries/C and C++

%description -n libotmixmod0
Development libraries for otmixmod library.

%package devel
Summary:        otmixmod development files
Group:          Development/Libraries/C and C++
Requires:       libotmixmod0 = %{version}
Requires:       openturns-devel

%description devel
Development files for otmixmod library.

%package -n python3-%{name}
Summary:        otmixmod library
Group:          Productivity/Scientific/Math
Requires:       python3-openturns
%description -n python3-%{name}
Python textual interface to otmixmod uncertainty library

%prep
%setup -q

%build
%cmake -DINSTALL_DESTDIR:PATH=%{buildroot} \
       -DCMAKE_SKIP_INSTALL_RPATH:BOOL=ON \
       -DCMAKE_UNITY_BUILD=ON .
%cmake_build

%install
%cmake_install

%check
export LD_LIBRARY_PATH=%{buildroot}%{_libdir}
%ctest --tests-regex pyinstallcheck --schedule-random

%post -n libotmixmod0 -p /sbin/ldconfig 
%postun -n libotmixmod0 -p /sbin/ldconfig 

%files -n libotmixmod0
%defattr(-,root,root,-)
%{_libdir}/*.so.*

%files devel
%defattr(-,root,root,-)
%dir %{_includedir}/%{name}
%{_includedir}/%{name}/*.h*
%{_includedir}/%{name}/swig/
%{_libdir}/*.so
%{_libdir}/cmake/

%files -n python3-%{name}
%defattr(-,root,root,-)
%{python_sitearch}/%{name}/
%{python_sitearch}/%{name}-*.dist-info/


%changelog
* Wed Nov 28 2012 Julien Schueller <schueller at phimeca dot com> 0.0-1
- Initial package creation

