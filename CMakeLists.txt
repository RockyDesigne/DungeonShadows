# CMakeList.txt : CMake project for TestGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("TestGame")

set(CMAKE_CXX_STANDARD 20)

set(SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/TestGame.cpp")

# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${SOURCES})

target_sources(${PROJECT_NAME} PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/src/Player.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/TileMap.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/Tile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/Torch.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/Sword.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/ActionHandler.cpp"
		)

if (MSVC AND WIN32 AND NOT MSVC_VERSION VERSION_LESS 142)

	target_link_options(${PROJECT_NAME} PUBLIC $<$<CONFIG:Debug>:/INCREMENTAL>)
	target_compile_options(${PROJECT_NAME} PUBLIC $<$<CONFIG:Debug>:/ZI>)

endif() #Asta este pentru build-uri incrementale, ajuta la a avea build time-uri rapide

target_include_directories(${PROJECT_NAME} PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/include"
		)

target_link_libraries(${PROJECT_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/extern/raylib.lib"
	 winmm.dll #raylib are nevoie de astea
	 gdi32.dll
		)

# TODO: Add tests and install targets if needed.
