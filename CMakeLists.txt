cmake_minimum_required(VERSION 3.19) 

project(pwdgen
    VERSION 1.0.0
)
find_library(OPENSSL_CRYPTO_LIBRARY
    NAMES crypto libcrypto
    PATHS "/usr/lib"
    NO_DEFAULT_PATH)
set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED
)

if (NOT OpenSSL_FOUND)
    message(WARNING "OpenSSL not found")
endif()

if (NOT DEFINED OPENSSL_CRYPTO_LIBRARIES)
    message(FATAL_ERROR "OpenSSL Crypto not found") 
 endif()
set(SOURCES 
    "crash.cpp"
    "genpw.cpp"
    "genhash.cpp"
    "gensalt.cpp"
)

add_library(${PROJECT_NAME} STATIC ${SOURCES}) 
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/headers
        ${CMAKE_CURRENT_LIST_DIR}
    PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} #[[OpenSSL::SSL]] ${OPENSSL_CRYPTO_LIBRARIES})
