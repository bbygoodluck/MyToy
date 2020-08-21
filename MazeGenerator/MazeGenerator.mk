##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=MazeGenerator
ConfigurationName      :=Release
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy
ProjectPath            :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/MazeGenerator
IntermediateDirectory  :=../build-$(ConfigurationName)/MazeGenerator
OutDir                 :=../build-$(ConfigurationName)/MazeGenerator
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=81112580
Date                   :=21/08/2020
CodeLitePath           :=E:/Tools/Programming/CodeLite
LinkerName             :=F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/x86_64-w64-mingw32-g++.exe
SharedObjectLinkerName :=F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/x86_64-w64-mingw32-g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/windres.exe
LinkOptions            :=  -mwindows  $(shell wx-config --debug=no --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/x86_64-w64-mingw32-gcc-ar.exe rcu
CXX      := F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/x86_64-w64-mingw32-g++.exe
CC       := F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/x86_64-w64-mingw32-gcc.exe
CXXFLAGS :=  -O2 -Wall $(shell wx-config --cxxflags --unicode=yes --debug=no) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(shell wx-config --cxxflags --unicode=yes --debug=no) $(Preprocessors)
ASFLAGS  := 
AS       := F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
WXWIN:=F:\MyData\Programming\Lib\wxWidgets-3.1.3
WXCFG:=/gcc_dll/mswu
Objects0=../build-$(ConfigurationName)/MazeGenerator/src_resource_resource.rc$(ObjectSuffix) ../build-$(ConfigurationName)/MazeGenerator/src_PanelMaze.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/MazeGenerator/src_MainFrame.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/MazeGenerator/src_MazeView.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/MazeGenerator/src_Cell.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/MazeGenerator/src_MazeGenerator.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/MazeGenerator/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\MazeGenerator" mkdir "..\build-$(ConfigurationName)\MazeGenerator"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\MazeGenerator" mkdir "..\build-$(ConfigurationName)\MazeGenerator"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/MazeGenerator/.d:
	@if not exist "..\build-$(ConfigurationName)\MazeGenerator" mkdir "..\build-$(ConfigurationName)\MazeGenerator"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/MazeGenerator/src_resource_resource.rc$(ObjectSuffix): src/resource/resource.rc
	$(RcCompilerName) -i "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/MazeGenerator/src/resource/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/src_resource_resource.rc$(ObjectSuffix) $(RcIncludePath)
../build-$(ConfigurationName)/MazeGenerator/src_PanelMaze.cpp$(ObjectSuffix): src/PanelMaze.cpp ../build-$(ConfigurationName)/MazeGenerator/src_PanelMaze.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/MazeGenerator/src/PanelMaze.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_PanelMaze.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/MazeGenerator/src_PanelMaze.cpp$(DependSuffix): src/PanelMaze.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/MazeGenerator/src_PanelMaze.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/MazeGenerator/src_PanelMaze.cpp$(DependSuffix) -MM src/PanelMaze.cpp

../build-$(ConfigurationName)/MazeGenerator/src_PanelMaze.cpp$(PreprocessSuffix): src/PanelMaze.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/MazeGenerator/src_PanelMaze.cpp$(PreprocessSuffix) src/PanelMaze.cpp

../build-$(ConfigurationName)/MazeGenerator/src_MainFrame.cpp$(ObjectSuffix): src/MainFrame.cpp ../build-$(ConfigurationName)/MazeGenerator/src_MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/MazeGenerator/src/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MainFrame.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/MazeGenerator/src_MainFrame.cpp$(DependSuffix): src/MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/MazeGenerator/src_MainFrame.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/MazeGenerator/src_MainFrame.cpp$(DependSuffix) -MM src/MainFrame.cpp

../build-$(ConfigurationName)/MazeGenerator/src_MainFrame.cpp$(PreprocessSuffix): src/MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/MazeGenerator/src_MainFrame.cpp$(PreprocessSuffix) src/MainFrame.cpp

../build-$(ConfigurationName)/MazeGenerator/src_MazeView.cpp$(ObjectSuffix): src/MazeView.cpp ../build-$(ConfigurationName)/MazeGenerator/src_MazeView.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/MazeGenerator/src/MazeView.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MazeView.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/MazeGenerator/src_MazeView.cpp$(DependSuffix): src/MazeView.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/MazeGenerator/src_MazeView.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/MazeGenerator/src_MazeView.cpp$(DependSuffix) -MM src/MazeView.cpp

../build-$(ConfigurationName)/MazeGenerator/src_MazeView.cpp$(PreprocessSuffix): src/MazeView.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/MazeGenerator/src_MazeView.cpp$(PreprocessSuffix) src/MazeView.cpp

../build-$(ConfigurationName)/MazeGenerator/src_Cell.cpp$(ObjectSuffix): src/Cell.cpp ../build-$(ConfigurationName)/MazeGenerator/src_Cell.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/MazeGenerator/src/Cell.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Cell.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/MazeGenerator/src_Cell.cpp$(DependSuffix): src/Cell.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/MazeGenerator/src_Cell.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/MazeGenerator/src_Cell.cpp$(DependSuffix) -MM src/Cell.cpp

../build-$(ConfigurationName)/MazeGenerator/src_Cell.cpp$(PreprocessSuffix): src/Cell.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/MazeGenerator/src_Cell.cpp$(PreprocessSuffix) src/Cell.cpp

../build-$(ConfigurationName)/MazeGenerator/src_MazeGenerator.cpp$(ObjectSuffix): src/MazeGenerator.cpp ../build-$(ConfigurationName)/MazeGenerator/src_MazeGenerator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/MazeGenerator/src/MazeGenerator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MazeGenerator.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/MazeGenerator/src_MazeGenerator.cpp$(DependSuffix): src/MazeGenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/MazeGenerator/src_MazeGenerator.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/MazeGenerator/src_MazeGenerator.cpp$(DependSuffix) -MM src/MazeGenerator.cpp

../build-$(ConfigurationName)/MazeGenerator/src_MazeGenerator.cpp$(PreprocessSuffix): src/MazeGenerator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/MazeGenerator/src_MazeGenerator.cpp$(PreprocessSuffix) src/MazeGenerator.cpp


-include ../build-$(ConfigurationName)/MazeGenerator//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


