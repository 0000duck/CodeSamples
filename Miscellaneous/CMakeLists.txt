Project(Miscellaneous)

File (GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cxx)

ForEach (file ${SOURCES})
	Get_FileName_Component (exeName ${file} NAME_WE)
	Set (ProjectName "Miscellaneous Tests ${exeName}")
	Set (exeName Miscellaneous-${exeName})
	Add_Executable(${exeName} ${file})
	Set_Target_Properties (
		${exeName} PROPERTIES 
		PROJECT_LABEL ${ProjectName}
		)
	Add_Test (NAME MiscellaneousTests-${exeName} COMMAND ${exeName})
EndForEach (file ${SOURCES})
