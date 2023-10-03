for the level loading i used json files that are loaded in using the rapidjson library
the soundsystem in the engine uses threading to check for sounds to play
the gameobjects are stored with shared_ptrs to manage the memory
peterpepper and the enemies are using states
all the controls are done through commands that can be assigned to keyboard or gamepad buttons
for the health and pepper amount i used observer pattern

CONTROLS:
F1 to skip level
M to mute game

Menu:
arrows/dpad -> navigation
enter/A button -> confirm
type name then enter to start

Game:
arrows/dpad -> navigation
space/A button -> pepper