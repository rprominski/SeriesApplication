cmake_minimum_required(VERSION 3.12)
project(SeriesApplication)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
add_executable(SeriesApplication src/main.cpp src/FileWriter.cpp
        include/FileWriter.h src/Series.cpp include/Series.h src/Movie.cpp include/Movie.h include/FollowingSeries.h
        src/FollowingSeries.cpp include/Pool.h src/UserInterface.cpp include/UserInterface.h src/LiveStream.cpp
        include/LiveStream.h src/EventsReminder.cpp include/EventsReminder.h src/MovieFacade.cpp include/MovieFacade.h
        src/InputValidator.cpp include/InputValidator.h src/MessagePrinter.cpp include/MessagePrinter.h
        src/DataCollector.cpp include/DataCollector.h)