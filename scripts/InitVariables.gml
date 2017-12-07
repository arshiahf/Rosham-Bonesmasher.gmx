// Constants
global.ROCK = 'r';
global.ROCKBUTTON = ord('J');
global.PAPER = 'p';
global.PAPERBUTTON = ord('K');
global.SCISSORS = 's';
global.SCISSORSBUTTON = ord('L');
global.STARTKEY = "";
global.PATTERNKEY = "";
global.LEARNINGKEY = "";
global.NORMAL = "normal";
global.HARD = "hard";
global.HARDER = "harder";
global.ADAPTIVEPATTERN = "adaptivepattern";
global.ADAPTIVELEARNING = "adaptivelearning";
global.WIN = "w";
global.ROUNDWIN = "W";
global.TIE = "t";
global.LOSE = "l";
global.ROUNDLOSE = "L";

// RPS variables
global.difficulty = "";
global.playerHistory = "";
global.cpuHistory = "";
global.playerResultHistory = "";
global.cpuResultHistory = "";

// Number Trackers
global.playerNumWins = 0;
global.cpuNumWins = 0;
global.roundWins = 0;
global.roundTies = 0;
global.roundLosses = 0;
global.numWinsNeeded = 15;
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
