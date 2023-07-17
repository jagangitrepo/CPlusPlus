-- premake5.lua
workspace "CPlusPlus"
   configurations { "Debug", "Release" }

project "CPlusPlus"
   kind "ConsoleApp"
   language "C++"
   cppdialect 'c++17'
   targetdir "bin/%{cfg.buildcfg}"

   files { 
      "main.cpp",
      "include/**.h",
      "Structures&Classes/**.*",
      "Pointers&References/**.*"
   }

   includedirs {
      "include"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"