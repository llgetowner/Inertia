# -*- cmake -*-

project(llimage)

include(00-Common)
include(LLAddBuildTest)
include(LLCommon)
include(LLImage)
include(LLMath)
include(LLVFS)
include(ZLIB)

include_directories(
    ${LLCOMMON_INCLUDE_DIRS}
    ${LLMATH_INCLUDE_DIRS}
    ${LLVFS_INCLUDE_DIRS}
    ${PNG_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIRS}
    )

set(llimage_SOURCE_FILES
    llimagebmp.cpp
    llimage.cpp
    llimagedxt.cpp
    llimagej2c.cpp
    llimagejpeg.cpp
    llimagepng.cpp
    llimagetga.cpp
    llimageworker.cpp
    llpngwrapper.cpp
    )

set(llimage_HEADER_FILES
    CMakeLists.txt

    llimage.h
    llimagebmp.h
    llimagedxt.h
    llimagej2c.h
    llimagejpeg.h
    llimagepng.h
    llimagetga.h
    llimageworker.h
    llmapimagetype.h
    llpngwrapper.h
    )

set_source_files_properties(${llimage_HEADER_FILES}
                            PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND llimage_SOURCE_FILES ${llimage_HEADER_FILES})

add_library (llimage ${llimage_SOURCE_FILES})
add_dependencies(llimage prepare)
target_link_libraries(
    llimage
    ${JPEG_LIBRARIES}
    ${PNG_LIBRARIES}
    ${ZLIB_LIBRARIES}
    )

# Add tests
if (NOT STANDALONE)
	ADD_BUILD_TEST(llimageworker llimage)
endif (NOT STANDALONE)
