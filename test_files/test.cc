#include <stdint.h>

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int read_rom_file(const char *rom_file_name, ifstream &rom_file) {
  int read_size(0);
  rom_file.open(rom_file_name);
  if (!rom_file.is_open()) {
    cout << "rom file open fail!" << endl;
    return -1;
  }
  return 0;
}

void print_rom_file_first_ver(ifstream &rom_file){
  int read_16byte = 100;
  uint16_t byte2_buf(0);
  for(int i=0; i<read_16byte && !rom_file.eof(); i++) {
    rom_file.read(reinterpret_cast<char*>(&byte2_buf), 2);
    cout << hex << byte2_buf << "\t";
  }
  cout << endl;
  return;
}

int main(int argc, char *argv[]) {
  if(argc <2) {
    cout << "usage: " <<string(argv[0]) << " <nes_file_name>" <<endl;
    return 0;
  }

  cout <<"opening rom file " <<argv[1] << endl;

  ifstream rom_file;
  read_rom_file(argv[1], rom_file);

  print_rom_file_first_ver(rom_file);

  return 0;
}

