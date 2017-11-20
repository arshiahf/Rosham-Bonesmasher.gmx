// Constants
global.ROCK = 'r';
global.ROCKBUTTON = ord('J');
global.PAPER = 'p';
global.PAPERBUTTON = ord('K');
global.SCISSORS = 's';
global.SCISSORSBUTTON = ord('L');
global.NORMAL = "normal";
global.HARD = "hard";
global.HARDER = "harder";
global.ADAPTIVEPATTERN = "adaptivepattern";
global.ADAPTIVELEARNING = "adaptivelearning";
global.WIN = "w";
global.TIE = "t";
global.LOSE = "l";

// RPS variables
global.difficulty = global.ADAPTIVELEARNING;
global.playerHistory = "";
global.cpuHistory = "";
global.playerResultHistory = "";
global.cpuResultHistory = "";

// Number Trackers
global.playerWins = 0;
global.cpuWins = 0;
global.cpuvscpuRounds = 100;
global.patternWins = 0;
global.patternLosses = 0;
global.learningWins = 0;
global.learningLosses = 0;
global.totalPatternRounds = 0;
global.totalLearningRounds = 0;

// File Variables
global.playerName = "";
global.saveDir = "saves\";
global.cpuTrackerFile = "cpuTracker";
