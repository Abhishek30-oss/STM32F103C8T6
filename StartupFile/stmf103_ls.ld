ENTRY(Reset_Handler)


/* Memory Definitions */
MEMORY
{
	FLASH(rx):ORIGIN = 0x08000000, LENGTH = 64K
	SRAM(rwx):ORIGIN = 0x20000000, LENGTH = 20k
}


/*Sections Commands */
/*used to merge different sections and assign the address to final executable file*/

SECTIONS
{
     /*these section consist all the section that goes into flash*/
	 
	.text :
	{
		
		*(.isr_vector)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
		_etext = .;		/*location counter always updates virtual memory addres */
	} >FLASH			/*>FLASH AT> FLASH */
	
	/*these section consist the data section that will be copied into ram*/
	
	.data : 
	{
	  _ssram = .;
	  *(.data)
	  . = ALIGN(4);
	  _esram = .;
	} >SRAM AT> FLASH
	
	.bss :
	{
	    _ssram_bss = .;
		*(.bss)
		. = ALIGN(4);
		_esram_bss = .;
	} >SRAM
}


