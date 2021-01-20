#include "stdio.h"
#include "undo.h"

void UndoAksi(Stack *S, Aksi *X)
/* Menghapus aksi sebelumnya dari stack */
{
    printf("Aksi Anda sebelumnya telah dihapus!");
    Pop(S,X);
}
    