##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=RosePattern
ConfigurationName      :=Release
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy
ProjectPath            :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/RosePattern
IntermediateDirectory  :=../build-$(ConfigurationName)/RosePattern
OutDir                 :=../build-$(ConfigurationName)/RosePattern
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
Objects0=../build-$(ConfigurationName)/RosePattern/src_resource_resource.rc$(ObjectSuffix) ../build-$(ConfigurationName)/RosePattern/src_RosePatternView.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/RosePattern/src_MainFrame.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/RosePattern/src_PanelRosePattern.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/RosePattern/src_RosePattern.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/RosePattern/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\RosePattern" mkdir "..\build-$(ConfigurationName)\RosePattern"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\RosePattern" mkdir "..\build-$(ConfigurationName)\RosePattern"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/RosePattern/.d:
	@if not exist "..\build-$(ConfigurationName)\RosePattern" mkdir "..\build-$(ConfigurationName)\RosePattern"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/RosePattern/src_resource_resource.rc$(ObjectSuffix): src/resource/resource.rc
	$(RcCompilerName) -i "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/RosePattern/src/resource/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/src_resource_resource.rc$(ObjectSuffix) $(RcIncludePath)
../build-$(ConfigurationName)/RosePattern/src_RosePatternView.cpp$(ObjectSuffix): src/RosePatternView.cpp ../build-$(ConfigurationName)/RosePattern/src_RosePatternView.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/RosePattern/src/RosePatternView.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_RosePatternView.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/RosePattern/src_RosePatternView.cpp$(DependSuffix): src/RosePatternView.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/RosePattern/src_RosePatternView.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/RosePattern/src_RosePatternView.cpp$(DependSuffix) -MM src/RosePatternView.cpp

../build-$(ConfigurationName)/RosePattern/src_RosePatternView.cpp$(PreprocessSuffix): src/RosePatternView.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/RosePattern/src_RosePatternView.cpp$(PreprocessSuffix) src/RosePatternView.cpp

../build-$(ConfigurationName)/RosePattern/src_MainFrame.cpp$(ObjectSuffix): src/MainFrame.cpp ../build-$(ConfigurationName)/RosePattern/src_MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/RosePattern/src/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MainFrame.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/RosePattern/src_MainFrame.cpp$(DependSuffix): src/MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/RosePattern/src_MainFrame.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/RosePattern/src_MainFrame.cpp$(DependSuffix) -MM src/MainFrame.cpp

../build-$(ConfigurationName)/RosePattern/src_MainFrame.cpp$(PreprocessSuffix): src/MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/RosePattern/src_MainFrame.cpp$(PreprocessSuffix) src/MainFrame.cpp

../build-$(ConfigurationName)/RosePattern/src_PanelRosePattern.cpp$(ObjectSuffix): src/PanelRosePattern.cpp ../build-$(ConfigurationName)/RosePattern/src_PanelRosePattern.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/RosePattern/src/PanelRosePattern.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_PanelRosePattern.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/RosePattern/src_PanelRosePattern.cpp$(DependSuffix): src/PanelRosePattern.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/RosePattern/src_PanelRosePattern.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/RosePattern/src_PanelRosePattern.cpp$(DependSuffix) -MM src/PanelRosePattern.cpp

../build-$(ConfigurationName)/RosePattern/src_PanelRosePattern.cpp$(PreprocessSuffix): src/PanelRosePattern.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/RosePattern/src_PanelRosePattern.cpp$(PreprocessSuffix) src/PanelRosePattern.cpp

../build-$(ConfigurationName)/RosePattern/src_RosePattern.cpp$(ObjectSuffix): src/RosePattern.cpp ../build-$(ConfigurationName)/RosePattern/src_RosePattern.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/RosePattern/src/RosePattern.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_RosePattern.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/RosePattern/src_RosePattern.cpp$(DependSuffix): src/RosePattern.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/RosePattern/src_RosePattern.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/RosePattern/src_RosePattern.cpp$(DependSuffix) -MM src/RosePattern.cpp

../build-$(ConfigurationName)/RosePattern/src_RosePattern.cpp$(PreprocessSuffix): src/RosePattern.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/RosePattern/src_RosePattern.cpp$(PreprocessSuffix) src/RosePattern.cpp


-include ../build-$(ConfigurationName)/RosePattern//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


