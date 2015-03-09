# Install script for directory: /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/amf/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/decision_stump/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/det/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/emst/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/fastmks/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/gmm/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/hmm/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/kernel_pca/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/kmeans/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/lars/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/linear_regression/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/local_coordinate_coding/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/logistic_regression/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/lsh/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/naive_bayes/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/nca/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/neighbor_search/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/nmf/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/pca/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/perceptron/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/quic_svd/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/radical/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/range_search/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/rann/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/regularized_svd/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/sparse_autoencoder/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/sparse_coding/cmake_install.cmake")
  INCLUDE("/home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/nystroem_method/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

