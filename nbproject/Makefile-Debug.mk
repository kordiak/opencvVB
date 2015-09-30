#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11
CXXFLAGS=-std=c++11

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=/usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgcodecs.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videoio.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv: /usr/local/lib/libopencv_core.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv: /usr/local/lib/libopencv_highgui.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv: /usr/local/lib/libopencv_imgcodecs.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv: /usr/local/lib/libopencv_imgproc.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv: /usr/local/lib/libopencv_video.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv: /usr/local/lib/libopencv_videoio.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	g++ -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
