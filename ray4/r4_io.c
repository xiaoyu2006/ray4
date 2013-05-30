/****************************************************************************
//
//  File:  r4_io.c
//
//          This file contains the I/O routines needed for the Ray4 4D
//      raytracer.  See the r4_main.c header for more information on Ray4.
//      This version of r4_io.c contains Unix-based I/O routines.
//
//  Revisions:
//    1.00  30-Sep-90  Steve R. Hollasch
//          Initial version.
//
****************************************************************************/

#include <fcntl.h>
#include <stdio.h>

#include "ray4.h"
#include "r4_globals.h"


	/***  Local Global Variables  ***/

FILE *instream  = nil;	/* Input Stream */
int   outstream = 0;	/* Output Stream */



/****************************************************************************
//  These procedures close the input and output streams.
****************************************************************************/

void  CloseInput  ()
{
   if (!infile || (*infile == 0) || (!instream))
      return;
   fclose (instream);
   instream = nil;
}

void  CloseOutput  ()
{
   if (!outstream)
      return;
   close (outstream);
   outstream = 0;
}



/****************************************************************************
//  This routine returns then next character from the input stream.  If the
//  end of file is reached, it returns -1.
****************************************************************************/

short  ReadChar  ()
{
   return getc (instream);
}



/****************************************************************************
//  This subroutine opens the input file.  If no filename was given in the
//  command-line arguments, we'll use the standard input stream.
****************************************************************************/

void  OpenInput  ()
{
   if (!infile || (*infile == 0))
      instream = stdin;
   else if (! (instream = fopen (infile, "r")))
      Halt ("Open failed on input file (%s).", infile);
}



/****************************************************************************
//  This subroutine opens the output file.
****************************************************************************/

void  OpenOutput  ()
{
   if (!outfile || (*outfile == 0))
      Halt ("No output file specified.");

   if (-1 == (outstream = open (outfile, O_TRUNC|O_CREAT|O_WRONLY, 0666)))
      Halt ("Open failed on output file (%s).", outfile);
}



/****************************************************************************
//  This routine writes a block to the output file.
****************************************************************************/

void  WriteBlock  (buff, num)
   char   *buff;	/* Source Buffer */
   ulong   num;		/* Number of Bytes to Write */
{
   if (num != write (outstream, buff, (int)(num)))
      Halt ("Write error to output file; aborting");
}
