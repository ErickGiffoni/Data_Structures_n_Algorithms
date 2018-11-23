#include <stdio.h>

void mov_disk(int disk, char orig, char aux, char dest);
void print_mov(int disk);

int main()
{
    int disk;

    printf("\nEnter with disc amount:\n");
    
    scanf("%d", &disk);
    
    print_mov(disk);
    
    mov_disk(disk, 'A', 'B', 'C');
    
    return 0;
}

void mov_disk(int disk, char orig, char aux, char dest)
{
    if (disk == 1)
    {
        printf("Move disk 1 from %c to %c\n", orig, dest);
        return;
    }

    mov_disk(disk-1, orig, dest, aux);

    printf("Move disc %d from %c to %c\n", disk, orig, dest);

    mov_disk(disk-1, aux, orig, dest);
}

void print_mov(int disk)
{
    int movAmount = 1;

    for (int i = 0; i < disk; i++)
        movAmount *= 2;

    movAmount -= 1;    

    printf("\nMoviment Amount = %d\n\n", movAmount);
}