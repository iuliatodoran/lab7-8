cmake_minimum_required(VERSION 3.21)
project(Lab7_8)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab7_8
        .idea/.gitignore
        .idea/Lab7-8.iml
        .idea/modules.xml
        .idea/workspace.xml
        x64/Debug/Lab8_MIR.tlog/CL.command.1.tlog
        x64/Debug/Lab8_MIR.tlog/CL.read.1.tlog
        x64/Debug/Lab8_MIR.tlog/CL.write.1.tlog
        x64/Debug/Lab8_MIR.tlog/Lab8_MIR.lastbuildstate
        x64/Debug/Lab8_MIR.tlog/link.command.1.tlog
        x64/Debug/Lab8_MIR.tlog/link.read.1.tlog
        x64/Debug/Lab8_MIR.tlog/link.write.1.tlog
        x64/Debug/EntityTests.obj
        x64/Debug/Expenses.obj
        x64/Debug/Lab8_MIR.exe.recipe
        x64/Debug/Lab8_MIR.ilk
        x64/Debug/Lab8_MIR.log
        x64/Debug/main.obj
        x64/Debug/monthExpense.obj
        x64/Debug/RepoTests.obj
        x64/Debug/UI.obj
        x64/Debug/vc143.idb
        x64/Debug/vc143.pdb
        EntityTests.cpp
        EntityTests.h
        Expenses.cpp
        Expenses.h
        Lab8_MIR.vcxproj
        Lab8_MIR.vcxproj.filters
        Lab8_MIR.vcxproj.user
        main.cpp
        monthExpense.cpp
        monthExpense.h
        RepoTests.cpp
        RepoTests.h
        UI.cpp
        UI.h)
