cmake_minimum_required(VERSION 3.13)
project(games-score-statistics C)

set(CMAKE_C_STANDARD 11)
add_executable(games-score-statistics main.c src/services/start.h src/services/start.c src/views/_ui.c src/views/_ui.h src/logs/log.h src/logs/log.c lib/str.c lib/str.h lib/stdhead.h src/objects/school.c src/objects/school.h src/objects/contact.c src/objects/contact.h src/objects/project.c src/objects/project.h src/datastructs/list.c src/datastructs/list.h src/datastructs/stack.c src/datastructs/stack.h src/services/input_info.c src/services/input_info.h src/services/output_info.c src/services/output_info.h src/services/sort.c src/services/sort.h)
