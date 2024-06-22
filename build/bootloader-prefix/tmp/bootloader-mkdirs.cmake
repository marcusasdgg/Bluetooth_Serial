# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/marcu/esp/esp-idf/components/bootloader/subproject"
  "C:/Users/marcu/OneDrive/Documents/PlatformIO/Projects/Bluetooth_Serial/build/bootloader"
  "C:/Users/marcu/OneDrive/Documents/PlatformIO/Projects/Bluetooth_Serial/build/bootloader-prefix"
  "C:/Users/marcu/OneDrive/Documents/PlatformIO/Projects/Bluetooth_Serial/build/bootloader-prefix/tmp"
  "C:/Users/marcu/OneDrive/Documents/PlatformIO/Projects/Bluetooth_Serial/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/marcu/OneDrive/Documents/PlatformIO/Projects/Bluetooth_Serial/build/bootloader-prefix/src"
  "C:/Users/marcu/OneDrive/Documents/PlatformIO/Projects/Bluetooth_Serial/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/marcu/OneDrive/Documents/PlatformIO/Projects/Bluetooth_Serial/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/marcu/OneDrive/Documents/PlatformIO/Projects/Bluetooth_Serial/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
