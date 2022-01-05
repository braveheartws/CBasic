cmake_minimum_required(VERSION 3.20)
project(CBasic C)

set(CMAKE_C_STANDARD 99)

add_executable(CBasic main.c util.h include/helper.h helper.c main1.c util.c)
