ENTRY(main);
SECTIONS
{
  . = 0x1000;
  .text : AT(0x1000)
  {
		_text = .;
    *(.text);
		_text_end = .;
  }
  /DISCARD/ :
  {
		*(.note*);
		*(.iplt*);
		*(.igot*);
		*(.rel*);
		*(.comment);
  }
}
