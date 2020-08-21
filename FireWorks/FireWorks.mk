##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=FireWorks
ConfigurationName      :=Release
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy
ProjectPath            :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/FireWorks
IntermediateDirectory  :=../build-$(ConfigurationName)/FireWorks
OutDir                 :=../build-$(ConfigurationName)/FireWorks
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
Objects0=../build-$(ConfigurationName)/FireWorks/src_resource_resource.rc$(ObjectSuffix) ../build-$(ConfigurationName)/FireWorks/src_FireworksApp.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/FireWorks/src_PanelFireworks.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/FireWorks/src_FireworksView.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/FireWorks/src_MainFrame.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/FireWorks/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\FireWorks" mkdir "..\build-$(ConfigurationName)\FireWorks"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\FireWorks" mkdir "..\build-$(ConfigurationName)\FireWorks"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/FireWorks/.d:
	@if not exist "..\build-$(ConfigurationName)\FireWorks" mkdir "..\build-$(ConfigurationName)\FireWorks"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/FireWorks/src_resource_resource.rc$(ObjectSuffix): src/resource/resource.rc
	$(RcCompilerName) -i "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/FireWorks/src/resource/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/src_resource_resource.rc$(ObjectSuffix) $(RcIncludePath)
../build-$(ConfigurationName)/FireWorks/src_FireworksApp.cpp$(ObjectSuffix): src/FireworksApp.cpp ../build-$(ConfigurationName)/FireWorks/src_FireworksApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/FireWorks/src/FireworksApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_FireworksApp.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/FireWorks/src_FireworksApp.cpp$(DependSuffix): src/FireworksApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/FireWorks/src_FireworksApp.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/FireWorks/src_FireworksApp.cpp$(DependSuffix) -MM src/FireworksApp.cpp

../build-$(ConfigurationName)/FireWorks/src_FireworksApp.cpp$(PreprocessSuffix): src/FireworksApp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/FireWorks/src_FireworksApp.cpp$(PreprocessSuffix) src/FireworksApp.cpp

../build-$(ConfigurationName)/FireWorks/src_PanelFireworks.cpp$(ObjectSuffix): src/PanelFireworks.cpp ../build-$(ConfigurationName)/FireWorks/src_PanelFireworks.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/FireWorks/src/PanelFireworks.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_PanelFireworks.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/FireWorks/src_PanelFireworks.cpp$(DependSuffix): src/PanelFireworks.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/FireWorks/src_PanelFireworks.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/FireWorks/src_PanelFireworks.cpp$(DependSuffix) -MM src/PanelFireworks.cpp

../build-$(ConfigurationName)/FireWorks/src_PanelFireworks.cpp$(PreprocessSuffix): src/PanelFireworks.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/FireWorks/src_PanelFireworks.cpp$(PreprocessSuffix) src/PanelFireworks.cpp

../build-$(ConfigurationName)/FireWorks/src_FireworksView.cpp$(ObjectSuffix): src/FireworksView.cpp ../build-$(ConfigurationName)/FireWorks/src_FireworksView.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/FireWorks/src/FireworksView.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_FireworksView.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/FireWorks/src_FireworksView.cpp$(DependSuffix): src/FireworksView.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/FireWorks/src_FireworksView.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/FireWorks/src_FireworksView.cpp$(DependSuffix) -MM src/FireworksView.cpp

../build-$(ConfigurationName)/FireWorks/src_FireworksView.cpp$(PreprocessSuffix): src/FireworksView.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/FireWorks/src_FireworksView.cpp$(PreprocessSuffix) src/FireworksView.cpp

../build-$(ConfigurationName)/FireWorks/src_MainFrame.cpp$(ObjectSuffix): src/MainFrame.cpp ../build-$(ConfigurationName)/FireWorks/src_MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/FireWorks/src/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MainFrame.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/FireWorks/src_MainFrame.cpp$(DependSuffix): src/MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/FireWorks/src_MainFrame.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/FireWorks/src_MainFrame.cpp$(DependSuffix) -MM src/MainFrame.cpp

../build-$(ConfigurationName)/FireWorks/src_MainFrame.cpp$(PreprocessSuffix): src/MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/FireWorks/src_MainFrame.cpp$(PreprocessSuffix) src/MainFrame.cpp


-include ../build-$(ConfigurationName)/FireWorks//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


