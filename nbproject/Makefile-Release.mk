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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/source/Application.o \
	${OBJECTDIR}/source/ButtonsList.o \
	${OBJECTDIR}/source/Calibrator.o \
	${OBJECTDIR}/source/ElementDetector.o \
	${OBJECTDIR}/source/FieldWithText.o \
	${OBJECTDIR}/source/FileReader.o \
	${OBJECTDIR}/source/ImageSource.o \
	${OBJECTDIR}/source/PLYGenerator.o \
	${OBJECTDIR}/source/Painter.o \
	${OBJECTDIR}/source/SASimple.o \
	${OBJECTDIR}/source/SearchingAlgorithmBase.o \
	${OBJECTDIR}/source/ViewThread.o \
	${OBJECTDIR}/source/WindowController.o \
	${OBJECTDIR}/source/WindowView.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tesopencv ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/source/Application.o: source/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Application.o source/Application.cpp

${OBJECTDIR}/source/ButtonsList.o: source/ButtonsList.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ButtonsList.o source/ButtonsList.cpp

${OBJECTDIR}/source/Calibrator.o: source/Calibrator.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Calibrator.o source/Calibrator.cpp

${OBJECTDIR}/source/ElementDetector.o: source/ElementDetector.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ElementDetector.o source/ElementDetector.cpp

${OBJECTDIR}/source/FieldWithText.o: source/FieldWithText.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FieldWithText.o source/FieldWithText.cpp

${OBJECTDIR}/source/FileReader.o: source/FileReader.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FileReader.o source/FileReader.cpp

${OBJECTDIR}/source/ImageSource.o: source/ImageSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ImageSource.o source/ImageSource.cpp

${OBJECTDIR}/source/PLYGenerator.o: source/PLYGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/PLYGenerator.o source/PLYGenerator.cpp

${OBJECTDIR}/source/Painter.o: source/Painter.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Painter.o source/Painter.cpp

${OBJECTDIR}/source/SASimple.o: source/SASimple.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SASimple.o source/SASimple.cpp

${OBJECTDIR}/source/SearchingAlgorithmBase.o: source/SearchingAlgorithmBase.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SearchingAlgorithmBase.o source/SearchingAlgorithmBase.cpp

${OBJECTDIR}/source/ViewThread.o: source/ViewThread.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ViewThread.o source/ViewThread.cpp

${OBJECTDIR}/source/WindowController.o: source/WindowController.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/WindowController.o source/WindowController.cpp

${OBJECTDIR}/source/WindowView.o: source/WindowView.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/WindowView.o source/WindowView.cpp

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
