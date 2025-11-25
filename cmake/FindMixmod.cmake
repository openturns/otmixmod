# - Find Mixmod
# Classification with Mixture Modelling
# available at https://github.com/mixmod
#
# The module defines the following variables:
#  MIXMOD_FOUND - the system has LibSVM
#  MIXMOD_INCLUDE_DIR - where to find svm.h
#  MIXMOD_INCLUDE_DIRS - libsvm includes
#  MIXMOD_LIBRARY - where to find the LibSVM library
#  MIXMOD_LIBRARIES - aditional libraries
#  MIXMOD_ROOT_DIR - root dir (ex. /usr/local)

#=============================================================================
# Copyright 2010-2023, Julien Schueller
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met: 
# 
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer. 
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution. 
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# The views and conclusions contained in the software and documentation are those
# of the authors and should not be interpreted as representing official policies, 
# either expressed or implied, of the FreeBSD Project.
#=============================================================================

# set MIXMOD_INCLUDE_DIR
find_path (MIXMOD_INCLUDE_DIR
  NAMES
    mixmod.h
)


# set MIXMOD_INCLUDE_DIRS
set (MIXMOD_INCLUDE_DIRS ${MIXMOD_INCLUDE_DIR})

# set MIXMOD_LIBRARY
find_library (MIXMOD_LIBRARY
  NAMES
    mixmod
  DOC
    "Mixmod library location"
)

# set MIXMOD_LIBRARIES
set (MIXMOD_LIBRARIES ${MIXMOD_LIBRARY})



# try to guess root dir from include dir
if (MIXMOD_INCLUDE_DIR)
  string (REGEX REPLACE "(.*)/include.*" "\\1" MIXMOD_ROOT_DIR ${MIXMOD_INCLUDE_DIR})
# try to guess root dir from library dir
elseif (MIXMOD_LIBRARY)
  string (REGEX REPLACE "(.*)/lib[/|32|64].*" "\\1" MIXMOD_ROOT_DIR ${MIXMOD_LIBRARY})
endif ()


# handle REQUIRED and QUIET options
include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (Mixmod REQUIRED_VARS MIXMOD_LIBRARY MIXMOD_INCLUDE_DIR)

mark_as_advanced (
  MIXMOD_LIBRARY
  MIXMOD_LIBRARIES
  MIXMOD_INCLUDE_DIR
  MIXMOD_INCLUDE_DIRS
  MIXMOD_ROOT_DIR
)
