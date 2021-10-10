##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Plan
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Dominik/Desktop/Plan/Plan
ProjectPath            :=C:/Users/Dominik/Desktop/Plan/Plan/Plan
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Dominik
Date                   :=14/12/2020
CodeLitePath           :="E:/Program Files/CodeLite"
LinkerName             :=E:/MinGW/bin/g++.exe
SharedObjectLinkerName :=E:/MinGW/bin/g++.exe -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Plan.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=E:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := E:/MinGW/bin/ar.exe rcu
CXX      := E:/MinGW/bin/g++.exe
CC       := E:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Przedmiot.cpp$(ObjectSuffix) $(IntermediateDirectory)/Nauczyciel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Nad_grupa.cpp$(ObjectSuffix) $(IntermediateDirectory)/Grupa.cpp$(ObjectSuffix) $(IntermediateDirectory)/Sala.cpp$(ObjectSuffix) $(IntermediateDirectory)/Zajecia.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dominik/Desktop/Plan/Plan/Plan/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Przedmiot.cpp$(ObjectSuffix): Przedmiot.cpp $(IntermediateDirectory)/Przedmiot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dominik/Desktop/Plan/Plan/Plan/Przedmiot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Przedmiot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Przedmiot.cpp$(DependSuffix): Przedmiot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Przedmiot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Przedmiot.cpp$(DependSuffix) -MM Przedmiot.cpp

$(IntermediateDirectory)/Przedmiot.cpp$(PreprocessSuffix): Przedmiot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Przedmiot.cpp$(PreprocessSuffix) Przedmiot.cpp

$(IntermediateDirectory)/Nauczyciel.cpp$(ObjectSuffix): Nauczyciel.cpp $(IntermediateDirectory)/Nauczyciel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dominik/Desktop/Plan/Plan/Plan/Nauczyciel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Nauczyciel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Nauczyciel.cpp$(DependSuffix): Nauczyciel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Nauczyciel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Nauczyciel.cpp$(DependSuffix) -MM Nauczyciel.cpp

$(IntermediateDirectory)/Nauczyciel.cpp$(PreprocessSuffix): Nauczyciel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Nauczyciel.cpp$(PreprocessSuffix) Nauczyciel.cpp

$(IntermediateDirectory)/Nad_grupa.cpp$(ObjectSuffix): Nad_grupa.cpp $(IntermediateDirectory)/Nad_grupa.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dominik/Desktop/Plan/Plan/Plan/Nad_grupa.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Nad_grupa.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Nad_grupa.cpp$(DependSuffix): Nad_grupa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Nad_grupa.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Nad_grupa.cpp$(DependSuffix) -MM Nad_grupa.cpp

$(IntermediateDirectory)/Nad_grupa.cpp$(PreprocessSuffix): Nad_grupa.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Nad_grupa.cpp$(PreprocessSuffix) Nad_grupa.cpp

$(IntermediateDirectory)/Grupa.cpp$(ObjectSuffix): Grupa.cpp $(IntermediateDirectory)/Grupa.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dominik/Desktop/Plan/Plan/Plan/Grupa.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Grupa.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Grupa.cpp$(DependSuffix): Grupa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Grupa.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Grupa.cpp$(DependSuffix) -MM Grupa.cpp

$(IntermediateDirectory)/Grupa.cpp$(PreprocessSuffix): Grupa.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Grupa.cpp$(PreprocessSuffix) Grupa.cpp

$(IntermediateDirectory)/Sala.cpp$(ObjectSuffix): Sala.cpp $(IntermediateDirectory)/Sala.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dominik/Desktop/Plan/Plan/Plan/Sala.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sala.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sala.cpp$(DependSuffix): Sala.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Sala.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Sala.cpp$(DependSuffix) -MM Sala.cpp

$(IntermediateDirectory)/Sala.cpp$(PreprocessSuffix): Sala.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sala.cpp$(PreprocessSuffix) Sala.cpp

$(IntermediateDirectory)/Zajecia.cpp$(ObjectSuffix): Zajecia.cpp $(IntermediateDirectory)/Zajecia.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dominik/Desktop/Plan/Plan/Plan/Zajecia.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Zajecia.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Zajecia.cpp$(DependSuffix): Zajecia.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Zajecia.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Zajecia.cpp$(DependSuffix) -MM Zajecia.cpp

$(IntermediateDirectory)/Zajecia.cpp$(PreprocessSuffix): Zajecia.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Zajecia.cpp$(PreprocessSuffix) Zajecia.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


