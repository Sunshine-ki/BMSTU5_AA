#ifndef _DEFINE_H_

#define _DEFINE_H_

#define LEN 100 // max количество вершин в графе
#define INF 1e6
#define MAX_LEN_STATION 128

#define TRUE 1
#define FALSE 0
#define NOT_FOUND -1

#define OK 0

#define ERROR_OPEN_FILE -1
#define ERROR_EXEC -1

#define DEPTH_OF_RECURSION 1500

#define ANTS_MAX_COUNT 100

#define MAX_LEN_FILE_NAME 32
#define MSG_LEN 32


// #define FILE_NAME "graph/graph.gv" // "graph/three.gv" //  // "graph/grh2.gv"

#define PHEROMONE_MIN 0.1

#define RESULT_FILE_NAME "result/result.gv"
#define RESULT_FILE_NAME_PNG "result/result.png"

#define CREATE_RESULT_FILE "sfdp -Tpng " RESULT_FILE_NAME " -o " RESULT_FILE_NAME_PNG
#define OPEN_RESULT_FILE "xdg-open " RESULT_FILE_NAME_PNG

#define TEXT_INFO_BEGIN "\
graph G\n\
{\n\
    edge[color=\"gray54\",fontcolor=\"blue\",fontsize=12, len=3];\n\
    node[color=\"indigo\",fontsize=14, shape=\"septagon\"];\n\n"

#define TEXT_INFO_END "}"

#endif