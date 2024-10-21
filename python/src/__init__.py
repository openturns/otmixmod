"""
    otmixmod --- The Mixmod interface for Open TURNS
    ===================================================

    Contents
    --------
      'otmixmod' is a python module for Open TURNS that allows to use
      the Mixmod software to build Open TURNS objects.

"""

# flake8: noqa

# ensures swig type tables order & dll load
import openturns as _ot

from .otmixmod import *

__version__ = '0.18'
