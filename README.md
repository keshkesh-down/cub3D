# so_long
## This project is a very small 2D game. It is built to make you work with textures, sprites. And some very basic gameplay elements.

![Запись экрана 2022-06-22 в 06 14 19](https://user-images.githubusercontent.com/58878384/174935962-6dfd05ec-1a3a-434b-af25-68da1cb9c3f6.gif)

### How to play
The game is able to play any map you want as long as it follow some specific rules:

- The map has to be a `.ber` file.
- It can only contain some of the following characters:

Character | Object
---|---
1	| Wall.
0	| Empty space.
C	| Collectable.
E	| Exit.
P	| Player starting position.
Q | Enemy.

- The map must be a rectangle surrounded by walls ‘1’.
- It must have at least one exit ‘E’. And only one player ‘P’.

*See some examples in the `maps` folder of this project.*
 
Use `WASD` or `← → ↑ ↓` to move. You move one tile at a time.
 
In future: 
- [ ] Add lvl-generator.
- [ ] Add menu (settings, level selection).
- [ ] Add music.

#### Makefile
`make` to compile the game.

`make clean` to delete `*.o` files.

`make fclean` to delete `*.o` and program files.

`make re` to delete `*.o` and program files, and, to compile the game.
