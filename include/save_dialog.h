#ifndef GUARD_SAVE_DIALOG_H
#define GUARD_SAVE_DIALOG_H

void SaveDialog_InitSave(void);
void SaveDialog_InitBattlePyramidRetire(void);
void Task_SaveDialogHandleBattlePyramidRetire(u8 taskId);
void Task_SaveDialogHandleSave(u8 taskId);
void SaveDialog_AutoSave(void);


#endif  // GUARD_SAVE_DIALOG_H
