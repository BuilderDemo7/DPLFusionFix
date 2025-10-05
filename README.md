# Driver: Parallel Lines - Fusion Fix
This is a project that aims to fix issues and add small features in the PC port of DRIVER: Parallel Lines (2007)

## Releases
You can get the latest release [here](https://github.com/BuilderDemo7/DPLFusionFix/releases),
it is highly recommended to pick the "Release" version as it's more compatible.

## Installation
1. Download the latest release
2. Extract the files inside the .zip file of the release in the folder where Driver: Parallel Lines is installed

## Configuration
Jump to [Settings](https://github.com/BuilderDemo7/DPLFusionFix/tree/master?tab=readme-ov-file#settings) if you want to see the list of the adjustable settings
of the .ini file.

### Garage Camera
To configure the controls for using the garage camera go in Settings -> Controls -> Customize Controls -> Visuals,
once you're there, bind the "Camera Look Left", "Camera Look Right", "Camera Look Back" and "Camera Look Forward",
If you're playing on a keyboard you can simply bind these to JKLO but if you're playing on a joystick/gamepad just use the right analogic stick.

### Turn signals
The turn signals are using the arrow left and arrow right or D-pad left and D-pad right for alternating between both directions by default.

## License & Warranty
The code is open-source, allowing anyone to obtain and edit the code.

## Features
- Garage camera restored
- Debug menu restored (enable it by renaming the files: GUI/Frontend to GUI/Dev)
- Fix: crashes on Era change or going back to the menu
### Optional features
#### Graphics
- PS2 version like glow/bloom effects
- 3 Adjustable draw distance clamps.
#### Misc
- Turn signals (left arrow or right arrow/D-pad left or D-pad right)
- Classic burnout
- Goons icons in mini-map will have a similar appearence as in DRIV3R.

## Settings
You can adjust the settings simply by editing the **dplfusionfix_userconfig.ini** file.

### Renderer
- **Draw_Distance1=260.000000**, adjusts the first draw-distance's value.
- **Draw_Distance2=435.000000**, adjusts the second draw-distance's value.
- **Draw_Distance3=510.000000**, adjusts the third draw-distance's value.
- **Vehicles_HeadLight_DegreesAngle=60.000000**, adjusts the vehicles' headlight shader's angle in degrees.
- **PS2_Glow_Effects_Settings=True**, when set to **True**, the game will have similar glow/bloom effects to the PS2 version of the game.
- **Background_Glow_In_ShaderVer_1=True**, when set to **True**, Shader version 2.0x won't be required to enable the glow/bloom effects.
### Game
- **Allow_Missions_Debug_Text=False**, allows the missions debugging text to be printed out in the console output, you can enable the console output at **Misc -> Show_Console_Output=True**.
- **Dev_Menu_On=False**, when set to **True**, it enables the debug button in the pause menu to enter the debug menu that is now functional.
- **Instances_Spawn_Radius=210.000000**, the higher this value is, the more the range of NPCs spawning within T.K.'s area will increase, be aware that this can give infinite loading screens when the value is too high.
### Misc
- **Show_Console_Output=False**, shows a console window associated with the Driver: Parallel Lines' window.
- **Windowed_Mode=False**, enables the windowed mode of the game which is still in beta and might have a few bugs, good for running the game in background.
- **Pause_Game_In_Windowed_Mode=False**, will pause the game when set to **True** if the window of the game is not focused.
- **Invert_Garage_Camera=False**, will invert the garage's camera when set to **True**, useful if you're used to the PS2 version's inverted camera look.
- **Classic_BurnOut=False**, when set to **True**, the burnout will work like in previous games of the franchise.
### New_Visual
- **Minimap_Driver3_Goons=True**, when the value is **True**, thugs icons in the mini-map will have a similar appearence as in DRIV3R.
### New_Feature
- **Player_Can_Use_Turn_Signal=True**, when the value is **True**, the player will be able to use the turn signals just like the civilians, use left arrow or right arrow to switch between them.