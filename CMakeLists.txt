Project (CodeSamples)

CMake_Minimum_Required (VERSION 3.3.0)
Set (EMACS_SERVER_NAME "CODE-SAMPLES")

Include (${CMAKE_SOURCE_DIR}/CMake/Config.cmake)

Include_Cmake_Module(Macros)
Include_Cmake_Module(Targets)

If (NOT CMAKE_BUILD_TYPE)
  Set (CMAKE_BUILD_TYPE "Debug")
EndIf (NOT CMAKE_BUILD_TYPE)

Include_Directories (
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/Global/Include
  )

Set (ParseArgsLib "parse_args")
Include_Directories (${CMAKE_SOURCE_DIR}/CommandLineArgs)
Add_Subdirectory (CommandLineArgs)

Macro (ADD_SUBDIRECTORY_IF p_varName p_dirName)
  If (${p_varName})
    Add_Subdirectory (${p_dirName})
  EndIf (${p_varName})
EndMacro (ADD_SUBDIRECTORY_IF)

If (CMAKE_COMPILER_IS_GNUCXX)
  Set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated -Wno-unused-local-typedefs")
EndIf (CMAKE_COMPILER_IS_GNUCXX)

If (WIN32)
  Add_Definitions("-DBOOST_ALL_DYN_LINK")
EndIf (WIN32)

OPTION (USE_GTKMM "Use Gtkmm Samples" FALSE)
OPTION (BUILD_SAMPLES_MULTI_INDEX "Build Multi Index Samples" FALSE)
OPTION (BUILD_SAMPLES_PYTHON "Build Boost Python Samples" FALSE)
OPTION (BUILD_SAMPLES_FUSION "Build Fusion Samples" FALSE)
OPTION (BUILD_SAMPLES_FILE_READING "Build File Reading Samples" FALSE)
OPTION (BUILD_SAMPLES_MISCELLANEOUS "Build Miscellaneous Samples" FALSE)
OPTION (BUILD_SAMPLES_NG "Build NG Samples" FALSE)
OPTION (BUILD_SAMPLES_PREPROCESSOR "Build PreProcessor Samples" FALSE)
OPTION (BUILD_SAMPLES_PHOENIX "Build Phoenix Samples" FALSE)
OPTION (BUILD_SAMPLES_SPIRIT "Build Spirit Samples" FALSE)
OPTION (BUILD_SAMPLES_PROPERTY_TREE "Build Property Tree Samples" FALSE)
OPTION (BUILD_SAMPLES_HOLIDAYS "Build Holidays Samples" FALSE)
OPTION (BUILD_SAMPLES_TEMPLATES "Build Templates Samples" FALSE)
OPTION (BUILD_SAMPLES_CPP "Build CPP Samples" FALSE)
OPTION (BUILD_SAMPLES_DOWNLOAD_FILE "Build Download File Samples" FALSE)
OPTION (BUILD_SAMPLES_PERL "Build Perl Samples" FALSE)
OPTION (BUILD_SAMPLES_PERL_CPP "Build Perl Cpp Samples" FALSE)
OPTION (BUILD_SAMPLES_XML "Build XML Samples" FALSE)
OPTION (BUILD_SAMPLES_MPL "Build MPL Samples" FALSE)
OPTION (BUILD_SAMPLES_XERCES "Build Xerces Samples" FALSE)
OPTION (BUILD_SAMPLES_ZORBA "Build Zorba Samples" FALSE)
OPTION (BUILD_SAMPLES_SIGNALS "Build Signals Samples" FALSE)
OPTION (BUILD_SAMPLES_OSG "Build OSG Samples" FALSE)
OPTION (BUILD_SAMPLES_DSA "Build DSA Samples" FALSE)
OPTION (BUILD_SAMPLES_ALG "Build ALG Samples" FALSE)
OPTION (BUILD_KDTREE "Build KDtree" FALSE)
OPTION (BUILD_SAMPLES_OGL_QT "Build QtOpenGL Samples" FALSE)
OPTION (BUILD_SAMPLES_QT "Build Qt Samples" FALSE)
OPTION (BUILD_SAMPLES_OGL "Build OpenGL Samples" FALSE)
OPTION (BUILD_MT "Build MultiThreading Samples" FALSE)
OPTION (BUILD_ASIO "Build Asio Samples" FALSE)
OPTION (BUILD_SAMPLES_DEBUGGING "Build Debugging Samples" FALSE)
OPTION (BUILD_SAMPLES_BOOST "Build Boost Samples" FALSE)
OPTION (BUILD_SAMPLES_YAML "Build Yaml Samples" FALSE)
OPTION (BUILD_SAMPLES_JSON "Build Json Samples" FALSE)
OPTION (BUILD_SAMPLES_REST "Build Rest Samples" FALSE)

Add_Subdirectory_If (BUILD_SAMPLES_MULTI_INDEX Multi-Index)
Add_Subdirectory_If (BUILD_SAMPLES_PYTHON PyBindings)
Add_Subdirectory_If (BUILD_SAMPLES_FUSION Fusion)
Add_Subdirectory_If (BUILD_SAMPLES_FILE_READING FileReading)
Add_Subdirectory_If (BUILD_SAMPLES_MISCELLANEOUS Miscellaneous)
Add_Subdirectory_If (BUILD_SAMPLES_NG NG)
Add_Subdirectory_If (BUILD_SAMPLES_PREPROCESSOR PreProcessor)
Add_Subdirectory_If (BUILD_SAMPLES_PHOENIX Phoenix)
Add_Subdirectory_If (BUILD_SAMPLES_SPIRIT Spirit)
Add_Subdirectory_If (BUILD_SAMPLES_PROPERTY_TREE PropertyTree)
Add_Subdirectory_If (BUILD_SAMPLES_HOLIDAYS Holidays)
Add_Subdirectory_If (BUILD_SAMPLES_TEMPLATES Templates)
Add_Subdirectory_If (BUILD_SAMPLES_CPP CPP)
Add_Subdirectory_If (BUILD_SAMPLES_DOWNLOAD_FILE DownloadFile)
Add_Subdirectory_If (BUILD_SAMPLES_PERL Perl)
Add_Subdirectory_If (BUILD_SAMPLES_PERL_CPP PerlCpp)
Add_Subdirectory_If (BUILD_SAMPLES_XML XML)
Add_Subdirectory_If (BUILD_SAMPLES_MPL Mpl)
Add_Subdirectory_If (BUILD_SAMPLES_XERCES Xerces)
Add_Subdirectory_If (BUILD_SAMPLES_ZORBA Zorba)
Add_Subdirectory_If (BUILD_SAMPLES_SIGNALS Signals)
Add_Subdirectory_If (BUILD_SAMPLES_OSG OpenSceneGraph)
Add_Subdirectory_If (BUILD_SAMPLES_DSA DataStructures)
Add_Subdirectory_If (BUILD_SAMPLES_ALG Algorithms)
Add_Subdirectory_If (BUILD_KDTREE KDtree)
Add_Subdirectory_If (BUILD_SAMPLES_OGL_QT QtOpenGL)
Add_Subdirectory_If (BUILD_SAMPLES_QT Qt)
Add_Subdirectory_If (BUILD_SAMPLES_OGL OpenGL)
Add_Subdirectory_If (BUILD_MT MultiThreading)
Add_Subdirectory_If (BUILD_ASIO Asio)
Add_Subdirectory_If (BUILD_SAMPLES_DEBUGGING Debug-Code)
Add_Subdirectory_If (BUILD_SAMPLES_BOOST Boost)
Add_Subdirectory_If (BUILD_SAMPLES_YAML Yaml)
Add_Subdirectory_If (BUILD_SAMPLES_JSON Json)
Add_Subdirectory_If (BUILD_SAMPLES_REST Rest)

Find_File (
  PERL_IN_FILE
    test.pl.in
  PATHS
    ${CMAKE_SOURCE_DIR}
  )

Find_File (
  PYTHON_IN_FILE
  test.py.in
  PATHS
  ${CMAKE_SOURCE_DIR}
)

Find_File (
  PERL_ALL_TESTS_IN_FILE
    alltests.pl.in
  PATHS
    ${CMAKE_SOURCE_DIR}
  )

Find_File (
  PL_FILE_SAMPLES_EXE
    ProcessSamplesExeTemplate.pl
  PATHS
    ${CMAKE_SOURCE_DIR}
    )

Find_File(
  CMAKE_SAMPLES_TMPL
    test.pl.tmpl
  PATHS
    ${CMAKE_SOURCE_DIR}
    )

Configure_Executable_File (
  ${CMAKE_SOURCE_DIR}/Config/dot2svg
  ${CMAKE_BINARY_DIR}/dot2svg
  )

List (APPEND IncludeDirectories ${Boost_INCLUDE_DIR})
List (APPEND IncludeDirectories ${CMAKE_SOURCE_DIR})

Cmake_List_To_Args (EditorSearchDirectories -d ${IncludeDirectories})
Cmake_List_To_Args (ProjectModules -p ${PROJECT_MODULES})

Execute_Python (
  FILE ${PY_WRITE_EDITOR_FILE}
  ARGS 
  -y ${CMAKE_VARIABLES_YML_OUT_FILE}
  ${EditorSearchDirectories}
)

Configure_File(
  ${CMAKE_SOURCE_DIR}/CodeSamples.yml.in ${CMAKE_BINARY_DIR}/CodeSamples.yml @ONLY
  )
