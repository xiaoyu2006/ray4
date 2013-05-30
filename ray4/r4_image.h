/****************************************************************************
//
//  File:  r4_image.h
//
//      This file contains structure and constant declarations for the ray4
//    image file output format.
//
//      The following assumptions are made in the header structure:
//
//      - All fields are packed together (no space between fields).
//      - uchar  fields are unsigned  8-bit integers.
//      - ushort fields are unsigned 16-bit integers.
//      - ulong  fields are unsigned 32-bit integers.
//
//      The fields are as follows:
//
//      magic       :  Always set to 'Ray4' (0x52977934).
//      version     :  Lower is older.  Currently set to 1.
//      bitsperpixel:  Total bits for each pixel - red, green & blue.
//      aspect      :  Aspect ratio.  To form a perfect cube with all edges
//                     of equal length, it would be aspect[0] pixels in the
//                     X dimension, aspect[1] pixels in the Y dimension, and
//                     aspect[2] pixels in the Z dimension.
//      first       :  Starting corner of the image cube.
//      last        :  Ending corner of the image cube.  The dimension of
//                     the data is (last[0]-first[0]+1) horizontally,
//                     (last[1]-first[1]+1) vertically, and (last[2]-first[2]
//                     +1) deep.
//
//      The header structure size will be a multiple of longwords.
//
//      After the header follows the image data.  Each scanline consists of
//    RGB triples, where each triple is `bitsperpixel' long.  Scanlines are
//    stored left to right, top to bottom, back to front.  All scanlines
//    begin on even byte boundaries.
//
//  Revisions:
//    0.00  02-Oct-90  Steve R. Hollasch
//          Initial version.
//
****************************************************************************/

#ifndef R4_IMAGE_H
#define R4_IMAGE_H


   /*=========================*/
   /*  Structure Definitions  */
   /*=========================*/

typedef struct S_IMAGEHDR   ImageHdr;

   /* Note:  Keep the size of this structure a longword multiple for
   //        addressing convinience on most architectures.  */

struct S_IMAGEHDR
{  unsigned long   magic;	/* Magic Number */
   unsigned char   version;	/* Image File Version Number */
   unsigned char   bitsperpixel;/* Number of Bits per Pixel */
   unsigned short  aspect[3];	/* Aspect Ratios [X,Y,Z] */
   unsigned short  first[3];	/* Starting Image Pixels for [X,Y,Z] */
   unsigned short  last[3];	/* Ending Image Pixels for [X,Y,Z] */
};

#endif
