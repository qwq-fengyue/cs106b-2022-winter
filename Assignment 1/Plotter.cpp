#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {

    double x0 = 0, y0 = 0, x1 = 0, y1 = 0;
    PenStyle style = { 1, "black" };
    bool penState = 0;

    for (string line; getline(input, line); ) {
        Vector<string> commands = stringSplit(line, " ");
        string command = toLowerCase(commands[0]);

        if (command == "pendown") {
            penState = 1;
        }

        else if (command == "penup") {
            penState = 0;
        }

        else if (command == "moveabs") {
            x1 = stringToReal(commands[1]);
            y1 = stringToReal(commands[2]);
            if (penState) {
                drawLine(x0, y0, x1, y1, style);
            }
            x0 = x1;
            y0 = y1;
        }

        else if (command == "moverel") {
            x1 = x0 + stringToReal(commands[1]);
            y1 = y0 + stringToReal(commands[2]);
            if (penState) {
                drawLine(x0, y0, x1, y1, style);
            }
            x0 = x1;
            y0 = y1;
        }

         else if (command == "pencolor") {
            style.color = commands[1];
        }

        else if (command == "penwidth") {
            style.width = stringToReal(commands[1]);
        }
    }
    return;
}
