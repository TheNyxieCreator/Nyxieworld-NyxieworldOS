global long_mode_start
extern kernel_main, putpixel, drawline, fillrect

section .text
bits 64

long_mode_start:
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; Configurar modo de vídeo 1024x768x256 usando VESA
    mov ax, 0x4F02   ; Função VESA para definir modo de vídeo
    mov bx, 0x105    ; Modo 105h: 1024x768x256 cores
    int 0x10         ; Chamar a interrupção de vídeo da BIOS

    ; Adicionar mensagem de debug
    mov dword [0xb8000], 0x56494c4f ; 'OLIV' em hexadecimal

    ; Desenhar um retângulo para representar uma janela
    mov cx, 100
    mov dx, 100
    mov si, 200
    mov di, 150
    mov al, 0x1F     ; Cor azul
    call fillrect

    call kernel_main
    hlt
