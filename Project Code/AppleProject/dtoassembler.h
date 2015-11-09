#ifndef DTOASSEMBLER_H
#define DTOASSEMBLER_H

#include "publicationdto.h"
#include "presentationdto.h"
#include <sstream>

void assembleDTO(PublicationDTO *dto, vector<string> f);
void assembleDTO(PresentationDTO *dto, vector<string> f);
#endif // DTOASSEMBLER_H
