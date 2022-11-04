{"filter":false,"title":"Racetrack.h","tooltip":"/Practicum/Practicum 4/Racetrack.h","undoManager":{"mark":63,"position":63,"stack":[[{"start":{"row":0,"column":0},"end":{"row":41,"column":6},"action":"insert","lines":["#ifndef QUARTERBACK_H","#define QUARTERBACK_H","#include <iostream>","using namespace std;","","class Quarterback","{","    public:","        Quarterback();","        Quarterback(string, int, int, int, int, int);","        Quarterback(string);","        void setName(string);","        string getName();","        void setComp(int);","        int getComp();","        void setAtt(int);","        int getAtt();","        void setYards(int);","        int getYards();","        void setTD(int);","        int getTD();","        void setPick(int);","        int getPick();","        void PassCompleted(int);","        void PassAttempted();","        void Interception();","        float PasserRating();","        void Touchdown(int);","        ","    private:","     int pass_completes;","     int pass_attempts;","     int total_yards;","     int touchdowns;","     int intercepts;","     string name;","     ","        ","        ","};","","#endif"],"id":1}],[{"start":{"row":0,"column":8},"end":{"row":0,"column":21},"action":"remove","lines":["QUARTERBACK_H"],"id":2},{"start":{"row":0,"column":8},"end":{"row":0,"column":9},"action":"insert","lines":["R"]},{"start":{"row":0,"column":9},"end":{"row":0,"column":10},"action":"insert","lines":["A"]},{"start":{"row":0,"column":10},"end":{"row":0,"column":11},"action":"insert","lines":["C"]},{"start":{"row":0,"column":11},"end":{"row":0,"column":12},"action":"insert","lines":["E"]},{"start":{"row":0,"column":12},"end":{"row":0,"column":13},"action":"insert","lines":["T"]},{"start":{"row":0,"column":13},"end":{"row":0,"column":14},"action":"insert","lines":["R"]},{"start":{"row":0,"column":14},"end":{"row":0,"column":15},"action":"insert","lines":["A"]},{"start":{"row":0,"column":15},"end":{"row":0,"column":16},"action":"insert","lines":["C"]},{"start":{"row":0,"column":16},"end":{"row":0,"column":17},"action":"insert","lines":["K"]},{"start":{"row":0,"column":17},"end":{"row":0,"column":18},"action":"insert","lines":["."]}],[{"start":{"row":0,"column":17},"end":{"row":0,"column":18},"action":"remove","lines":["."],"id":3}],[{"start":{"row":0,"column":17},"end":{"row":0,"column":18},"action":"insert","lines":["_"],"id":4},{"start":{"row":0,"column":18},"end":{"row":0,"column":19},"action":"insert","lines":["H"]}],[{"start":{"row":1,"column":8},"end":{"row":1,"column":21},"action":"remove","lines":["QUARTERBACK_H"],"id":5},{"start":{"row":1,"column":8},"end":{"row":1,"column":19},"action":"insert","lines":["RACETRACK_H"]}],[{"start":{"row":5,"column":6},"end":{"row":5,"column":17},"action":"remove","lines":["Quarterback"],"id":6},{"start":{"row":5,"column":6},"end":{"row":5,"column":7},"action":"insert","lines":["R"]},{"start":{"row":5,"column":7},"end":{"row":5,"column":8},"action":"insert","lines":["a"]},{"start":{"row":5,"column":8},"end":{"row":5,"column":9},"action":"insert","lines":["c"]},{"start":{"row":5,"column":9},"end":{"row":5,"column":10},"action":"insert","lines":["e"]},{"start":{"row":5,"column":10},"end":{"row":5,"column":11},"action":"insert","lines":["t"]},{"start":{"row":5,"column":11},"end":{"row":5,"column":12},"action":"insert","lines":["r"]},{"start":{"row":5,"column":12},"end":{"row":5,"column":13},"action":"insert","lines":["a"]},{"start":{"row":5,"column":13},"end":{"row":5,"column":14},"action":"insert","lines":["c"]},{"start":{"row":5,"column":14},"end":{"row":5,"column":15},"action":"insert","lines":["k"]}],[{"start":{"row":8,"column":8},"end":{"row":27,"column":28},"action":"remove","lines":["Quarterback();","        Quarterback(string, int, int, int, int, int);","        Quarterback(string);","        void setName(string);","        string getName();","        void setComp(int);","        int getComp();","        void setAtt(int);","        int getAtt();","        void setYards(int);","        int getYards();","        void setTD(int);","        int getTD();","        void setPick(int);","        int getPick();","        void PassCompleted(int);","        void PassAttempted();","        void Interception();","        float PasserRating();","        void Touchdown(int);"],"id":7}],[{"start":{"row":11,"column":5},"end":{"row":16,"column":17},"action":"remove","lines":["int pass_completes;","     int pass_attempts;","     int total_yards;","     int touchdowns;","     int intercepts;","     string name;"],"id":8},{"start":{"row":11,"column":4},"end":{"row":11,"column":5},"action":"remove","lines":[" "]},{"start":{"row":11,"column":0},"end":{"row":11,"column":4},"action":"remove","lines":["    "]},{"start":{"row":10,"column":12},"end":{"row":11,"column":0},"action":"remove","lines":["",""]}],[{"start":{"row":8,"column":8},"end":{"row":8,"column":9},"action":"insert","lines":["R"],"id":9},{"start":{"row":8,"column":9},"end":{"row":8,"column":10},"action":"insert","lines":["a"]},{"start":{"row":8,"column":10},"end":{"row":8,"column":11},"action":"insert","lines":["c"]}],[{"start":{"row":8,"column":8},"end":{"row":8,"column":11},"action":"remove","lines":["Rac"],"id":10},{"start":{"row":8,"column":8},"end":{"row":8,"column":17},"action":"insert","lines":["Racetrack"]}],[{"start":{"row":8,"column":17},"end":{"row":8,"column":19},"action":"insert","lines":["()"],"id":11}],[{"start":{"row":8,"column":19},"end":{"row":8,"column":20},"action":"insert","lines":[";"],"id":12}],[{"start":{"row":8,"column":20},"end":{"row":9,"column":0},"action":"insert","lines":["",""],"id":13},{"start":{"row":9,"column":0},"end":{"row":9,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":9,"column":8},"end":{"row":9,"column":34},"action":"insert","lines":["RaceTrack(string raceName)"],"id":14}],[{"start":{"row":9,"column":25},"end":{"row":9,"column":33},"action":"remove","lines":["raceName"],"id":15},{"start":{"row":9,"column":24},"end":{"row":9,"column":25},"action":"remove","lines":[" "]}],[{"start":{"row":9,"column":25},"end":{"row":9,"column":26},"action":"insert","lines":[";"],"id":16}],[{"start":{"row":9,"column":26},"end":{"row":10,"column":0},"action":"insert","lines":["",""],"id":17},{"start":{"row":10,"column":0},"end":{"row":10,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":10,"column":8},"end":{"row":10,"column":9},"action":"insert","lines":["v"],"id":18},{"start":{"row":10,"column":9},"end":{"row":10,"column":10},"action":"insert","lines":["o"]},{"start":{"row":10,"column":10},"end":{"row":10,"column":11},"action":"insert","lines":["i"]},{"start":{"row":10,"column":11},"end":{"row":10,"column":12},"action":"insert","lines":["d"]}],[{"start":{"row":10,"column":12},"end":{"row":10,"column":13},"action":"insert","lines":[" "],"id":19}],[{"start":{"row":10,"column":13},"end":{"row":10,"column":30},"action":"insert","lines":["initDataMembers()"],"id":20}],[{"start":{"row":10,"column":30},"end":{"row":10,"column":31},"action":"insert","lines":[";"],"id":21}],[{"start":{"row":10,"column":31},"end":{"row":11,"column":0},"action":"insert","lines":["",""],"id":22},{"start":{"row":11,"column":0},"end":{"row":11,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":11,"column":8},"end":{"row":11,"column":9},"action":"insert","lines":["b"],"id":23},{"start":{"row":11,"column":9},"end":{"row":11,"column":10},"action":"insert","lines":["o"]},{"start":{"row":11,"column":10},"end":{"row":11,"column":11},"action":"insert","lines":["o"]},{"start":{"row":11,"column":11},"end":{"row":11,"column":12},"action":"insert","lines":["l"]}],[{"start":{"row":11,"column":12},"end":{"row":11,"column":13},"action":"insert","lines":[" "],"id":24}],[{"start":{"row":11,"column":13},"end":{"row":11,"column":52},"action":"insert","lines":["addCar(float topSpeed, string carModel)"],"id":25}],[{"start":{"row":11,"column":43},"end":{"row":11,"column":51},"action":"remove","lines":["carModel"],"id":26},{"start":{"row":11,"column":42},"end":{"row":11,"column":43},"action":"remove","lines":[" "]}],[{"start":{"row":11,"column":33},"end":{"row":11,"column":34},"action":"remove","lines":["d"],"id":27},{"start":{"row":11,"column":32},"end":{"row":11,"column":33},"action":"remove","lines":["e"]},{"start":{"row":11,"column":31},"end":{"row":11,"column":32},"action":"remove","lines":["e"]},{"start":{"row":11,"column":30},"end":{"row":11,"column":31},"action":"remove","lines":["p"]},{"start":{"row":11,"column":29},"end":{"row":11,"column":30},"action":"remove","lines":["S"]},{"start":{"row":11,"column":28},"end":{"row":11,"column":29},"action":"remove","lines":["p"]},{"start":{"row":11,"column":27},"end":{"row":11,"column":28},"action":"remove","lines":["o"]},{"start":{"row":11,"column":26},"end":{"row":11,"column":27},"action":"remove","lines":["t"]},{"start":{"row":11,"column":25},"end":{"row":11,"column":26},"action":"remove","lines":[" "]}],[{"start":{"row":11,"column":34},"end":{"row":11,"column":35},"action":"insert","lines":[";"],"id":28}],[{"start":{"row":11,"column":35},"end":{"row":12,"column":0},"action":"insert","lines":["",""],"id":29},{"start":{"row":12,"column":0},"end":{"row":12,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":12,"column":8},"end":{"row":12,"column":9},"action":"insert","lines":["f"],"id":30},{"start":{"row":12,"column":9},"end":{"row":12,"column":10},"action":"insert","lines":["l"]},{"start":{"row":12,"column":10},"end":{"row":12,"column":11},"action":"insert","lines":["o"]},{"start":{"row":12,"column":11},"end":{"row":12,"column":12},"action":"insert","lines":["a"]},{"start":{"row":12,"column":12},"end":{"row":12,"column":13},"action":"insert","lines":["t"]}],[{"start":{"row":12,"column":13},"end":{"row":12,"column":14},"action":"insert","lines":[" "],"id":31}],[{"start":{"row":12,"column":14},"end":{"row":12,"column":28},"action":"insert","lines":["calcAvgSpeed()"],"id":32}],[{"start":{"row":12,"column":28},"end":{"row":12,"column":29},"action":"insert","lines":[";"],"id":33}],[{"start":{"row":12,"column":29},"end":{"row":13,"column":0},"action":"insert","lines":["",""],"id":34},{"start":{"row":13,"column":0},"end":{"row":13,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":13,"column":8},"end":{"row":13,"column":9},"action":"insert","lines":["i"],"id":39},{"start":{"row":13,"column":9},"end":{"row":13,"column":10},"action":"insert","lines":["n"]},{"start":{"row":13,"column":10},"end":{"row":13,"column":11},"action":"insert","lines":["t"]}],[{"start":{"row":13,"column":11},"end":{"row":13,"column":12},"action":"insert","lines":[" "],"id":40}],[{"start":{"row":13,"column":12},"end":{"row":13,"column":42},"action":"insert","lines":["countAvailable(float minSpeed)"],"id":41}],[{"start":{"row":13,"column":40},"end":{"row":13,"column":41},"action":"remove","lines":["d"],"id":42},{"start":{"row":13,"column":39},"end":{"row":13,"column":40},"action":"remove","lines":["e"]},{"start":{"row":13,"column":38},"end":{"row":13,"column":39},"action":"remove","lines":["e"]},{"start":{"row":13,"column":37},"end":{"row":13,"column":38},"action":"remove","lines":["p"]},{"start":{"row":13,"column":36},"end":{"row":13,"column":37},"action":"remove","lines":["S"]},{"start":{"row":13,"column":35},"end":{"row":13,"column":36},"action":"remove","lines":["n"]},{"start":{"row":13,"column":34},"end":{"row":13,"column":35},"action":"remove","lines":["i"]},{"start":{"row":13,"column":33},"end":{"row":13,"column":34},"action":"remove","lines":["m"]},{"start":{"row":13,"column":32},"end":{"row":13,"column":33},"action":"remove","lines":[" "]}],[{"start":{"row":13,"column":33},"end":{"row":13,"column":34},"action":"insert","lines":[";"],"id":43}],[{"start":{"row":13,"column":34},"end":{"row":14,"column":0},"action":"insert","lines":["",""],"id":44},{"start":{"row":14,"column":0},"end":{"row":14,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":14,"column":8},"end":{"row":14,"column":9},"action":"insert","lines":["i"],"id":45},{"start":{"row":14,"column":9},"end":{"row":14,"column":10},"action":"insert","lines":["n"]},{"start":{"row":14,"column":10},"end":{"row":14,"column":11},"action":"insert","lines":["t"]}],[{"start":{"row":14,"column":11},"end":{"row":14,"column":12},"action":"insert","lines":[" "],"id":46}],[{"start":{"row":14,"column":12},"end":{"row":14,"column":46},"action":"insert","lines":["countAvailableModels(string model)"],"id":47}],[{"start":{"row":14,"column":44},"end":{"row":14,"column":45},"action":"remove","lines":["l"],"id":48},{"start":{"row":14,"column":43},"end":{"row":14,"column":44},"action":"remove","lines":["e"]},{"start":{"row":14,"column":42},"end":{"row":14,"column":43},"action":"remove","lines":["d"]},{"start":{"row":14,"column":41},"end":{"row":14,"column":42},"action":"remove","lines":["o"]},{"start":{"row":14,"column":40},"end":{"row":14,"column":41},"action":"remove","lines":["m"]},{"start":{"row":14,"column":39},"end":{"row":14,"column":40},"action":"remove","lines":[" "]}],[{"start":{"row":14,"column":40},"end":{"row":14,"column":41},"action":"insert","lines":[";"],"id":49}],[{"start":{"row":14,"column":41},"end":{"row":15,"column":0},"action":"insert","lines":["",""],"id":50},{"start":{"row":15,"column":0},"end":{"row":15,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":16,"column":4},"end":{"row":16,"column":8},"action":"remove","lines":["    "],"id":51},{"start":{"row":16,"column":0},"end":{"row":16,"column":4},"action":"remove","lines":["    "]},{"start":{"row":15,"column":8},"end":{"row":16,"column":0},"action":"remove","lines":["",""]},{"start":{"row":15,"column":4},"end":{"row":15,"column":8},"action":"remove","lines":["    "]},{"start":{"row":15,"column":0},"end":{"row":15,"column":4},"action":"remove","lines":["    "]},{"start":{"row":14,"column":41},"end":{"row":15,"column":0},"action":"remove","lines":["",""]}],[{"start":{"row":16,"column":4},"end":{"row":16,"column":5},"action":"remove","lines":[" "],"id":52},{"start":{"row":16,"column":0},"end":{"row":16,"column":4},"action":"remove","lines":["    "]},{"start":{"row":15,"column":12},"end":{"row":16,"column":0},"action":"remove","lines":["",""]}],[{"start":{"row":15,"column":12},"end":{"row":16,"column":0},"action":"insert","lines":["",""],"id":53},{"start":{"row":16,"column":0},"end":{"row":16,"column":4},"action":"insert","lines":["    "]}],[{"start":{"row":16,"column":4},"end":{"row":16,"column":8},"action":"insert","lines":["    "],"id":54}],[{"start":{"row":16,"column":8},"end":{"row":16,"column":9},"action":"insert","lines":["s"],"id":55},{"start":{"row":16,"column":9},"end":{"row":16,"column":10},"action":"insert","lines":["t"]},{"start":{"row":16,"column":10},"end":{"row":16,"column":11},"action":"insert","lines":["r"]},{"start":{"row":16,"column":11},"end":{"row":16,"column":12},"action":"insert","lines":["i"]},{"start":{"row":16,"column":12},"end":{"row":16,"column":13},"action":"insert","lines":["n"]},{"start":{"row":16,"column":13},"end":{"row":16,"column":14},"action":"insert","lines":["g"]}],[{"start":{"row":16,"column":14},"end":{"row":16,"column":15},"action":"insert","lines":[" "],"id":56},{"start":{"row":16,"column":15},"end":{"row":16,"column":16},"action":"insert","lines":["n"]},{"start":{"row":16,"column":16},"end":{"row":16,"column":17},"action":"insert","lines":["a"]},{"start":{"row":16,"column":17},"end":{"row":16,"column":18},"action":"insert","lines":["m"]},{"start":{"row":16,"column":18},"end":{"row":16,"column":19},"action":"insert","lines":["e"]},{"start":{"row":16,"column":19},"end":{"row":16,"column":20},"action":"insert","lines":[";"]}],[{"start":{"row":16,"column":20},"end":{"row":17,"column":0},"action":"insert","lines":["",""],"id":57},{"start":{"row":17,"column":0},"end":{"row":17,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":17,"column":8},"end":{"row":17,"column":9},"action":"insert","lines":["d"],"id":58},{"start":{"row":17,"column":9},"end":{"row":17,"column":10},"action":"insert","lines":["o"]},{"start":{"row":17,"column":10},"end":{"row":17,"column":11},"action":"insert","lines":["u"]},{"start":{"row":17,"column":11},"end":{"row":17,"column":12},"action":"insert","lines":["b"]},{"start":{"row":17,"column":12},"end":{"row":17,"column":13},"action":"insert","lines":["l"]},{"start":{"row":17,"column":13},"end":{"row":17,"column":14},"action":"insert","lines":["e"]}],[{"start":{"row":17,"column":14},"end":{"row":17,"column":15},"action":"insert","lines":[" "],"id":59}],[{"start":{"row":17,"column":15},"end":{"row":17,"column":21},"action":"insert","lines":["speeds"],"id":60}],[{"start":{"row":17,"column":21},"end":{"row":17,"column":23},"action":"insert","lines":["[]"],"id":61}],[{"start":{"row":17,"column":23},"end":{"row":17,"column":24},"action":"insert","lines":[";"],"id":62}],[{"start":{"row":17,"column":24},"end":{"row":18,"column":0},"action":"insert","lines":["",""],"id":63},{"start":{"row":18,"column":0},"end":{"row":18,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":17,"column":0},"end":{"row":18,"column":8},"action":"remove","lines":["        double speeds[];","        "],"id":64}],[{"start":{"row":17,"column":0},"end":{"row":18,"column":0},"action":"insert","lines":["        double speeds[];",""],"id":65}],[{"start":{"row":17,"column":8},"end":{"row":17,"column":9},"action":"insert","lines":["/"],"id":66},{"start":{"row":17,"column":9},"end":{"row":17,"column":10},"action":"insert","lines":["/"]}],[{"start":{"row":5,"column":6},"end":{"row":5,"column":15},"action":"remove","lines":["Racetrack"],"id":67},{"start":{"row":5,"column":6},"end":{"row":5,"column":15},"action":"insert","lines":["RaceTrack"]},{"start":{"row":8,"column":8},"end":{"row":8,"column":17},"action":"remove","lines":["Racetrack"]},{"start":{"row":8,"column":8},"end":{"row":8,"column":17},"action":"insert","lines":["RaceTrack"]}],[{"start":{"row":0,"column":0},"end":{"row":23,"column":6},"action":"remove","lines":["#ifndef RACETRACK_H","#define RACETRACK_H","#include <iostream>","using namespace std;","","class RaceTrack","{","    public:","        RaceTrack();","        RaceTrack(string);","        void initDataMembers();","        bool addCar(float, string);","        float calcAvgSpeed();","        int countAvailable(float);","        int countAvailableModels(string);","    private:","        string name;","        //double speeds[];","","        ","        ","};","","#endif"],"id":68},{"start":{"row":0,"column":0},"end":{"row":24,"column":9},"action":"insert","lines":["// #ifndef RACETRACK_H","// #define RACETRACK_H","// #include <iostream>","// using namespace std;","","class RaceTrack","{","    public:","        RaceTrack();","        RaceTrack(string);","        void initDataMembers();","        bool addCar(float, string);","        float calcAvgSpeed();","        int countAvailable(float);","        int countAvailableModels(string);","    private:","        string name;","        float speeds[100];","        string models[100];","        int nCars;","        ","        ","};","","// #endif"]}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":24,"column":9},"end":{"row":24,"column":9},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1544547050312,"hash":"ff93f1714f51dc91af4542b04bf2846f78bd10f5"}