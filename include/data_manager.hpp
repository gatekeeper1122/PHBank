#pragma once
/**
 * @file data_manager.hpp
 * @brief Data Manager
 */
#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP

#include <3ds/types.h>

#define LANG_EN 1
#define LANG_FR 2

#define PERSONAL_COUNT 826
#define PERSONAL_LENGTH 14

#define DEX_ABILITIES_COUNT 192
#define DEX_ABILITIES_LENGTH 16
#define DEX_ITEMS_COUNT 776
#define DEX_ITEMS_LENGTH 20
#define DEX_MOVES_COUNT 622
#define DEX_MOVES_LENGTH 20
#define DEX_NATURES_COUNT 25
#define DEX_NATURES_LENGTH 10
#define DEX_SPECIES_COUNT 722
#define DEX_SPECIES_LENGTH 20

class DataManager
{
	private:
		u8 _lang;
		u8 _personal[PERSONAL_COUNT][PERSONAL_LENGTH];
		u8 _abilities[DEX_ABILITIES_COUNT][DEX_ABILITIES_LENGTH];
		u8 _items[DEX_ITEMS_COUNT][DEX_ITEMS_LENGTH];
		u8 _moves[DEX_MOVES_COUNT][DEX_MOVES_LENGTH];
		u8 _natures[DEX_NATURES_COUNT][DEX_NATURES_LENGTH];
		u8 _species[DEX_SPECIES_COUNT][DEX_SPECIES_LENGTH];

	public:
		DataManager();
		~DataManager();

		Result load();

		const char* lang();
		const u8* personal(u32 species, u32 form);
		const u8* personal(u32 species);
		const u8* abilities(u32 ability);
		const u8* items(u32 item);
		const u8* moves(u32 move);
		const u8* natures(u32 nature);
		const u8* species(u32 species);
		const u8* HPTypes(u8 hiddenPower);

	private:
		Result loadData(char* path, u8* dest, u32 lineLength, u32 lineCount);
		Result loadDataLine(u8* src, u8* dst, u32 lineLength, u32 lineCount);
};

#endif // DATA_MANAGER_HPP