cpuTrackerRead = file_text_open_read(global.cpuTrackerFile);
if(cpuTrackerRead != -1)
{
    global.patternWins += file_text_read_real(cpuTrackerRead);
    global.patternLosses += file_text_read_real(cpuTrackerRead);
    global.learningWins += file_text_read_real(cpuTrackerRead);
    global.learningLosses += file_text_read_real(cpuTrackerRead);
    global.totalPatternRounds += file_text_read_real(cpuTrackerRead);
    global.totalLearningRounds += file_text_read_real(cpuTrackerRead);
}
file_text_close(cpuTrackerRead);

cpuTracker = file_text_open_write(global.cpuTrackerFile);
if(cpuTracker != -1)
{
    file_text_write_real(cpuTracker, global.patternWins);
    file_text_writeln(cpuTracker);
    file_text_write_real(cpuTracker, global.patternLosses);
    file_text_writeln(cpuTracker);
    file_text_write_real(cpuTracker, global.learningWins);
    file_text_writeln(cpuTracker);
    file_text_write_real(cpuTracker, global.learningLosses);
    file_text_writeln(cpuTracker);
    file_text_write_real(cpuTracker, global.totalPatternRounds);
    file_text_writeln(cpuTracker);
    file_text_write_real(cpuTracker, global.totalLearningRounds);
}
file_text_close(cpuTracker);
