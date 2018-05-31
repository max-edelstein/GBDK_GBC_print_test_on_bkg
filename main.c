#include <gb/gb.h>
#include <gb/cgb.h>
// above are required header files to use GBDK functionality

#include "max_pascal_test.c"  // contains the tile information
#include "max_pascal_test_map.c"  // contains the map data



/*****************************************************************************************************************************
Some notes about settings I used for creating the map "max_pascal_test_map.c" using GBMB from the tiles I made
using GBTD to make "max_pascal_test." 
I used 8x8 tiles even if using 8x16 sprites. 
I did not add color to the map, though I did add color to the tiles
when creating them in GBTD. Make sure you note the palette colors
down. Which can be found under view. Also make sure to be in the 
correct gameboy version for the tiles you are designing. In my case GBC palettes.
In GBMB -> map properties -> width 20  height 18 == 160x144 pixels
which is the size of the gameboy screen. Can be used for start/game over screen.
                                                         Name   Max    Bits
In GBMB -> Location properties -> palette    7        3
                                                    -> priority    1        1

When exporting in GBMB save as .c file and give meaningful name to Label which is the name of your
unsigned char array which is the data.  Remember to place const in front of the array file for fast compilation.
                                Property           Bits
Location format ->   [Tile number]   8
plane count 1 plane 8 bits
plane order Tiles are continues
****************************************************************************************************************************/


/***************************************************************************************************************************
* I am not the original author of this palette map setting program, I just edited this and experimented in an attempt   *
* to explain it to myself and hopefully others, the original creators contact can be found here                                      *
* Shen Mansell (shenmansell@hotmail.com)                                                                                                                 *
* where: http://shen.mansell.tripod.com                                                                                                                          *
* until I replaced the bung with test and examined CGB features with GBDK by Jasons article to create color bkg     *
* his email is drunk-ass@beer.com. and the source was from devrs.com                                                                     *                                                     
* also I wanted to note what the batch  file does                                                                                                            *
* lcc -Wl -yp0x143=0x80 -o bung.gb test.c first is the flag to the linkers and loaders telling we are using gbc             *
* so the gbc flag is set, I found this using gbdk documentation.                                                                                    *
* bung.gb is the name of the rom that will be  created when the bat file is ran. note that is you keep the previous     *
* gb in the same bin folder, when compiled again the old rom will be overwritten with the contents of of your main  *
* c file that you have been using. test.c is the name of the c file where all of the code will go. Note everything is    *
* written here using c and various gbdk requirements.                                                                                                *
* "pause" placed at the end of the .bat file forces the batch file to stay open after you run the bat file.                     *
*  pause is much like the equivalent of using return 0 or getchar in the main method to keep the program open     *
* the bat file is ran by double clicking the bat file                                                                                                         *
* the bat file is edited by you by right clicking and pressing edit                                                                                 * 
****************************************************************************************************************************/

                                                                                                          
// start of the main method
void main(void)       
{

          // LOADS TEMPLATE FROM tiles data
    set_bkg_data( 0, 4, max_pascal_test);  // loads 4 background tiles, T,E,S,T without colors into bkg memory



  VBK_REG = 1;  // required to show map

  // look in bkg memory and see how tiles aren't shown are blue T's, this is because by default non shown areas are the first
  // tile that was loaded into bkg memory, learned from videlais website
  // Set map data, 20 and  18 are the width and height of the gb/gbc screen. 
  // this sets the tiles to the visible screen starting off
  set_bkg_tiles( 0, 0, 20, 18, max_pascal_test_map );  // required

   VBK_REG = 0;  // required to show map
     

  set_bkg_tiles(0,0,20,18, max_pascal_test_map ); // required
 

     // THE DATA BELOW HERE IS TO SET THE COLORS OF THE INDIVIDUAL PALETTE ENTRIES
  set_bkg_palette_entry(0,0,RGB(31,31,31) );  // this is white
  set_bkg_palette_entry(0,1,RGB(31,31,31) );  // this is light grey was 23, 23 , 23
  set_bkg_palette_entry(0,2,RGB(31,31,31) );   // this is dark grey was 15 15 15
  set_bkg_palette_entry(0,3,RGB(3,6,31) );  // this is red color was 31, 0, 0


 // set four colors of the second palette
  set_bkg_palette_entry(1,0,RGB(31,31,31) );  // this is white
  set_bkg_palette_entry(1,1,RGB(31,31,31) );  // this is light grey was 23, 23 ,23
  set_bkg_palette_entry(1,2,RGB(31,31,31) );  // this is dark grey was 15, 15, 15
  set_bkg_palette_entry(1,3,RGB(30,31,8)   );  // this is blue was 0,0,31


  set_bkg_palette_entry(2,0,RGB(31,31,31) );  // this is white
  set_bkg_palette_entry(2,1,RGB(31,31,31) );  // this is light grey was 23, 23 , 23
  set_bkg_palette_entry(2,2,RGB(31,31,31) );   // this is dark grey was 15 15 15
  set_bkg_palette_entry(2,3,RGB(3,6,31) );  // this is red color was 31, 0, 0



  // set four colors of the fours tile palette
  set_bkg_palette_entry(3,0,RGB(31,31,31) );  // this is white
  set_bkg_palette_entry(3,1,RGB(31,31,31) );  // this is light grey was 23, 23 ,23
  set_bkg_palette_entry(3,2,RGB(31,31,31) );  // this is dark grey was 15, 15, 15
  set_bkg_palette_entry(3,3,RGB(30,31,8)   );  // this is blue was 0,0,31



   SHOW_BKG;
   DISPLAY_ON;


  while(1)
  {
   /*  The infinite loop here is just to keep the game open until you close the game much like using return 0 */
  /*   or getchar() to keep the console in a regular c program.                                                                           */
  } 



}   // end of the main method