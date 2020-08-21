##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Watch
ConfigurationName      :=Release
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy
ProjectPath            :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/Watch
IntermediateDirectory  :=../build-$(ConfigurationName)/Watch
OutDir                 :=../build-$(ConfigurationName)/Watch
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
Objects0=../build-$(ConfigurationName)/Watch/src_resource_resource.rc$(ObjectSuffix) ../build-$(ConfigurationName)/Watch/src_MainFrame.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Watch/src_WatchView.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Watch/src_PanelWatch.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Watch/src_Watch.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Watch/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Watch" mkdir "..\build-$(ConfigurationName)\Watch"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Watch" mkdir "..\build-$(ConfigurationName)\Watch"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Watch/.d:
	@if not exist "..\build-$(ConfigurationName)\Watch" mkdir "..\build-$(ConfigurationName)\Watch"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Watch/src_resource_resource.rc$(ObjectSuffix): src/resource/resource.rc
	$(RcCompilerName) -i "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/Watch/src/resource/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/src_resource_resource.rc$(ObjectSuffix) $(RcIncludePath)
../build-$(ConfigurationName)/Watch/src_MainFrame.cpp$(ObjectSuffix): src/MainFrame.cpp ../build-$(ConfigurationName)/Watch/src_MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/Watch/src/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MainFrame.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Watch/src_MainFrame.cpp$(DependSuffix): src/MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Watch/src_MainFrame.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Watch/src_MainFrame.cpp$(DependSuffix) -MM src/MainFrame.cpp

../build-$(ConfigurationName)/Watch/src_MainFrame.cpp$(PreprocessSuffix): src/MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Watch/src_MainFrame.cpp$(PreprocessSuffix) src/MainFrame.cpp

../build-$(ConfigurationName)/Watch/src_WatchView.cpp$(ObjectSuffix): src/WatchView.cpp ../build-$(ConfigurationName)/Watch/src_WatchView.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/Watch/src/WatchView.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_WatchView.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Watch/src_WatchView.cpp$(DependSuffix): src/WatchView.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Watch/src_WatchView.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Watch/src_WatchView.cpp$(DependSuffix) -MM src/WatchView.cpp

../build-$(ConfigurationName)/Watch/src_WatchView.cpp$(PreprocessSuffix): src/WatchView.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Watch/src_WatchView.cpp$(PreprocessSuffix) src/WatchView.cpp

../build-$(ConfigurationName)/Watch/src_PanelWatch.cpp$(ObjectSuffix): src/PanelWatch.cpp ../build-$(ConfigurationName)/Watch/src_PanelWatch.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/Watch/src/PanelWatch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_PanelWatch.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Watch/src_PanelWatch.cpp$(DependSuffix): src/PanelWatch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Watch/src_PanelWatch.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Watch/src_PanelWatch.cpp$(DependSuffix) -MM src/PanelWatch.cpp

../build-$(ConfigurationName)/Watch/src_PanelWatch.cpp$(PreprocessSuffix): src/PanelWatch.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Watch/src_PanelWatch.cpp$(PreprocessSuffix) src/PanelWatch.cpp

../build-$(ConfigurationName)/Watch/src_Watch.cpp$(ObjectSuffix): src/Watch.cpp ../build-$(ConfigurationName)/Watch/src_Watch.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/Watch/src/Watch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Watch.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Watch/src_Watch.cpp$(DependSuffix): src/Watch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Watch/src_Watch.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Watch/src_Watch.cpp$(DependSuffix) -MM src/Watch.cpp

../build-$(ConfigurationName)/Watch/src_Watch.cpp$(PreprocessSuffix): src/Watch.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Watch/src_Watch.cpp$(PreprocessSuffix) src/Watch.cpp


-include ../build-$(ConfigurationName)/Watch//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


