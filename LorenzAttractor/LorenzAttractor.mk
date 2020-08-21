##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=LorenzAttractor
ConfigurationName      :=Release
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy
ProjectPath            :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/LorenzAttractor
IntermediateDirectory  :=../build-$(ConfigurationName)/LorenzAttractor
OutDir                 :=../build-$(ConfigurationName)/LorenzAttractor
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
Objects0=../build-$(ConfigurationName)/LorenzAttractor/src_resource_resource.rc$(ObjectSuffix) ../build-$(ConfigurationName)/LorenzAttractor/src_PanelLorenz.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/LorenzAttractor/src_Lorenz.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/LorenzAttractor/src_MainFrame.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/LorenzAttractor/src_LorenzView.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/LorenzAttractor/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\LorenzAttractor" mkdir "..\build-$(ConfigurationName)\LorenzAttractor"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\LorenzAttractor" mkdir "..\build-$(ConfigurationName)\LorenzAttractor"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/LorenzAttractor/.d:
	@if not exist "..\build-$(ConfigurationName)\LorenzAttractor" mkdir "..\build-$(ConfigurationName)\LorenzAttractor"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/LorenzAttractor/src_resource_resource.rc$(ObjectSuffix): src/resource/resource.rc
	$(RcCompilerName) -i "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/LorenzAttractor/src/resource/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/src_resource_resource.rc$(ObjectSuffix) $(RcIncludePath)
../build-$(ConfigurationName)/LorenzAttractor/src_PanelLorenz.cpp$(ObjectSuffix): src/PanelLorenz.cpp ../build-$(ConfigurationName)/LorenzAttractor/src_PanelLorenz.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/LorenzAttractor/src/PanelLorenz.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_PanelLorenz.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/LorenzAttractor/src_PanelLorenz.cpp$(DependSuffix): src/PanelLorenz.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/LorenzAttractor/src_PanelLorenz.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/LorenzAttractor/src_PanelLorenz.cpp$(DependSuffix) -MM src/PanelLorenz.cpp

../build-$(ConfigurationName)/LorenzAttractor/src_PanelLorenz.cpp$(PreprocessSuffix): src/PanelLorenz.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/LorenzAttractor/src_PanelLorenz.cpp$(PreprocessSuffix) src/PanelLorenz.cpp

../build-$(ConfigurationName)/LorenzAttractor/src_Lorenz.cpp$(ObjectSuffix): src/Lorenz.cpp ../build-$(ConfigurationName)/LorenzAttractor/src_Lorenz.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/LorenzAttractor/src/Lorenz.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Lorenz.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/LorenzAttractor/src_Lorenz.cpp$(DependSuffix): src/Lorenz.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/LorenzAttractor/src_Lorenz.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/LorenzAttractor/src_Lorenz.cpp$(DependSuffix) -MM src/Lorenz.cpp

../build-$(ConfigurationName)/LorenzAttractor/src_Lorenz.cpp$(PreprocessSuffix): src/Lorenz.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/LorenzAttractor/src_Lorenz.cpp$(PreprocessSuffix) src/Lorenz.cpp

../build-$(ConfigurationName)/LorenzAttractor/src_MainFrame.cpp$(ObjectSuffix): src/MainFrame.cpp ../build-$(ConfigurationName)/LorenzAttractor/src_MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/LorenzAttractor/src/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MainFrame.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/LorenzAttractor/src_MainFrame.cpp$(DependSuffix): src/MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/LorenzAttractor/src_MainFrame.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/LorenzAttractor/src_MainFrame.cpp$(DependSuffix) -MM src/MainFrame.cpp

../build-$(ConfigurationName)/LorenzAttractor/src_MainFrame.cpp$(PreprocessSuffix): src/MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/LorenzAttractor/src_MainFrame.cpp$(PreprocessSuffix) src/MainFrame.cpp

../build-$(ConfigurationName)/LorenzAttractor/src_LorenzView.cpp$(ObjectSuffix): src/LorenzView.cpp ../build-$(ConfigurationName)/LorenzAttractor/src_LorenzView.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/LorenzAttractor/src/LorenzView.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LorenzView.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/LorenzAttractor/src_LorenzView.cpp$(DependSuffix): src/LorenzView.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/LorenzAttractor/src_LorenzView.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/LorenzAttractor/src_LorenzView.cpp$(DependSuffix) -MM src/LorenzView.cpp

../build-$(ConfigurationName)/LorenzAttractor/src_LorenzView.cpp$(PreprocessSuffix): src/LorenzView.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/LorenzAttractor/src_LorenzView.cpp$(PreprocessSuffix) src/LorenzView.cpp


-include ../build-$(ConfigurationName)/LorenzAttractor//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


