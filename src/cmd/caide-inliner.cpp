#include "../caideInliner.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <tclap/CmdLine.h>


using namespace std;

int main(int argc, const char* argv[]) {
    try {
        TCLAP::CmdLine cmd("CAIDE inliner");
        TCLAP::MultiArg<string> sourcesArg("s", "source", "Input files", true, "FILE PATH");
        cmd.add(sourcesArg);
        TCLAP::MultiArg<string> macrosArg("k", "keep-macros", "Macros to keep", false, "MACROS");
        cmd.add(macrosArg);
        TCLAP::UnlabeledMultiArg<string> clangArg("clang", "Clang flags", false, "CLANG FLAGS");
        cmd.add(clangArg);
        TCLAP::ValueArg<string> tempDirArg("t", "tempDir", "Temp directory", false, "./caide-tmp", "TEMPDIR");
        cmd.add(tempDirArg);
        TCLAP::ValueArg<string> outputArg("o", "output", "Output file", false, "./caide-tmp/result.cpp", "OUTPUT");
        cmd.add(outputArg);

        cmd.parse(argc, argv);

        caide::CppInliner inliner(tempDirArg.getValue());
        inliner.clangCompilationOptions = clangArg.getValue();
        inliner.macrosToKeep = macrosArg.getValue();

        inliner.inlineCode(sourcesArg.getValue(), outputArg.getValue());
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}