
text/x-generic header2.inc ( PHP script, ASCII text, with CRLF line terminators )
<?php
/**********************************************************************
    Copyright (C) FrontAccounting, LLC.
	Released under the terms of the GNU General Public License, GPL, 
	as published by the Free Software Foundation, either version 3 
	of the License, or (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
    See the License here <http://www.gnu.org/licenses/gpl-3.0.html>.
***********************************************************************/

/**
	Document blueprint use following parameters set in doctext.inc:

	$Addr1,	$Addr2 - address info
	$Payment_Terms - payment terms line
	$Footer - footer texts
	$this->company - company info
	$this->title - report title
	$this->formData - some other info
***/

		$this->row = $this->pageHeight - $this->topMargin;

		$upper = $this->row - 2 * $this->lineHeight;
		$lower = $this->bottomMargin + 8 * $this->lineHeight;
		$iline1 = $upper - 7.5 * $this->lineHeight;
		$iline2 = $iline1 - 8 * $this->lineHeight;
		$iline3 = $iline2 - 1.5 * $this->lineHeight;
		$iline4 = $iline3 - 1.5 * $this->lineHeight;
		$iline5 = $iline4 - 3 * $this->lineHeight;
		$iline6 = $iline5 - 1.5 * $this->lineHeight;
		$iline7 = $lower;
		$right = $this->pageWidth - $this->rightMargin;
		$width = ($right - $this->leftMargin) / 5;
		$icol = $this->pageWidth / 2;
		$ccol = $this->cols[0] + 4;
		$c2col = $ccol + 60;
		$ccol2 = $icol / 2;
		$mcol = $icol + 8;
		$mcol2 = $this->pageWidth - $ccol2;
		$cols = count($this->cols);
	
		$this->SetDrawColor(128, 128, 128);

//table for subtotal
// Adjust the coordinates to position the rectangle on the right side

// Calculate the width of the rectangles
$rectWidth = $right - $this->leftMargin - 350;

// Calculate the starting X position for the rectangles (top right)

if ($this->formData['doctype'] != ST_CUSTDELIVERY && $this->formData['doctype'] !=ST_STATEMENT ) {

$startX = $right - $rectWidth ;
$topY = $iline2+136;
// Border color and width
$borderColor = array(0, 0, 0); // Border color
$borderWidth = 0.5; // Border width

// Set border color and width
$this->SetLineWidth($borderWidth);
$this->SetDrawColor($borderColor);

// Rectangle 1 (top right)
$this->rect(
    $startX,
   $topY + 12,
    $rectWidth,
    $iline2 - $iline3,
    "D" // Draw border only
);
$this->rect(
    $startX,
   $topY - 6,
    $rectWidth,
    $iline2 - $iline3,
    "D" // Draw border only
);

// Rectangle 2 (top right)
$this->rect(
    $startX,
   $topY - 24,
    $rectWidth,
    $iline2 - $iline3,
    "D" // Draw border only
);

// Rectangle 3 (top right)
$this->rect(
    $startX,
   $topY - 42,
    $rectWidth,
    $iline2 - $iline3,
    "D" // Draw border only
);

// Rectangle 4 (top right)
$this->rect(
    $startX,
   $topY - 60,
    $rectWidth,
    $iline2 - $iline3,
    "D" // Draw border only
);

	$col = $this->leftMargin + 335;
for ($i = 0; $i < 1; $i++) {
    // Increase the height by increasing the difference between the Y coordinates
    $this->LineTo($col += $width + 15 , $iline2 - 402 + 15, $col , $iline4 - 457 + 15);
}

}
//for invoice details
// Calculate the width of the rectangles
$rectWidth = $right - $this->leftMargin - 370;

// Calculate the starting X position for the rectangles (top right)
$startX = $right - $rectWidth;

// Calculate the top Y position for the rectangles
$topY = $iline2-280;

// Border color and width
$borderColor = array(0, 0, 0); // Border color
$borderWidth = 0.5; // Border width

// Set border color and width
$this->SetLineWidth($borderWidth);
$this->SetDrawColor($borderColor);



// Rectangle 4 (top right)
$this->rect(
    $startX,
    $topY - 155,
    $rectWidth,
    $iline3 - $iline2, // Adjusted height for the rectangles to be at the top
    "D" // Draw border only
);
$this->rect(
    $startX,
    $topY - 137,
    $rectWidth,
    $iline3 - $iline2, // Adjusted height for the rectangles to be at the top
    "D" // Draw border only
);
$this->rect(
    $startX,
    $topY - 119,
    $rectWidth,
    $iline3 - $iline2, // Adjusted height for the rectangles to be at the top
    "D" // Draw border only
);




	
		
		$col = $this->leftMargin+350;
		for ($i = 0; $i < 1; $i++) {
    // Decrease the Y coordinates by the desired amount to reduce the height
   $this->LineTo($col += $width + 15, $iline2 + 83 + 58, $col, $iline4 +64 +58);

}

		$topOffset = -70; // Adjust this value to move the elements up
$tableHeightIncrease = -10; // Adjust this value to increase the table length

$this->rectangle($this->leftMargin, $iline5 + 30 - $topOffset, $right - $this->leftMargin, $iline5 - $iline6 + $tableHeightIncrease, "F", null, array(255, 255, 255));   

$this->Line($iline5 + 30 - $topOffset);
$this->Line($iline6 + 20 - $topOffset);
$this->Line($iline7 +21 - $topOffset);

$col = $this->leftMargin;

$this->LineTo($this->leftMargin, $iline5 + 30 - $topOffset, $this->leftMargin, $iline7 + 30 - $topOffset + $tableHeightIncrease);
if ($this->l['a_meta_dir'] == 'rtl') { // avoid line overwrite in rtl language
    $this->LineTo(540, $iline5 + 30 - $topOffset, 540, $iline7 + 30 - $topOffset + $tableHeightIncrease);
}
elseif($doctype == ST_CUSTDELIVERY) {
	 $this->LineTo(490, $iline5 + 30 - $topOffset, 490, $iline7 + 30 - $topOffset + $tableHeightIncrease);
}elseif($doctype == ST_PURCHORDER) {	
    $this->LineTo(535 + 4, $iline5 + 30 - $topOffset, 535 + 4, $iline7 + 30 - $topOffset + $tableHeightIncrease);
}elseif($doctype == ST_CUSTPAYMENT) {
	 $this->LineTo(490, $iline5 + 30 - $topOffset, 490, $iline7 + 30 - $topOffset + $tableHeightIncrease);
}elseif($doctype == ST_STATEMENT) {
	 $this->LineTo(490, $iline5 + 30 - $topOffset, 490, $iline7 + 30 - $topOffset + $tableHeightIncrease);

}else{
	 $this->LineTo(540 + 4, $iline5 + 30 - $topOffset, 540 + 4, $iline7 + 30 - $topOffset + $tableHeightIncrease);
}

$this->LineTo($right, $iline5 + 30 - $topOffset, $right, $iline7 + 30 - $topOffset + $tableHeightIncrease);

if ($doctype == ST_CUSTDELIVERY) {
    // Adjust lines for delivery document type
    $this->LineTo(60, $iline5 + 30 - $topOffset, 60, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(115, $iline5 + 30 - $topOffset, 115, $iline7 + 30 - $topOffset + $tableHeightIncrease);
	  $this->LineTo(390, $iline5 + 30 - $topOffset, 390, $iline7 + 30 - $topOffset + $tableHeightIncrease);
   
}elseif($doctype == ST_PURCHORDER){
	
    // Original lines for other document types
    $this->LineTo(90, $iline5 + 30 - $topOffset, 90, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(305, $iline5 + 30 - $topOffset, 305, $iline7 + 30 - $topOffset + $tableHeightIncrease);
  
    $this->LineTo(370, $iline5 + 30 - $topOffset, 370, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(435, $iline5 + 30 - $topOffset, 435, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(485, $iline5 + 30 - $topOffset, 485, $iline7 + 30 - $topOffset + $tableHeightIncrease);
	
}elseif($doctype == ST_CUSTPAYMENT){
	
    // Original lines for other document types
    $this->LineTo(100, $iline5 + 30 - $topOffset, 100, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(170, $iline5 + 30 - $topOffset, 170, $iline7 + 30 - $topOffset + $tableHeightIncrease);
  
    $this->LineTo(240, $iline5 + 30 - $topOffset, 240, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(310, $iline5 + 30 - $topOffset, 310, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(400, $iline5 + 30 - $topOffset, 400, $iline7 + 30 - $topOffset + $tableHeightIncrease);
	   
}elseif($doctype == ST_STATEMENT){
	
    // Original lines for other document types
    $this->LineTo(125, $iline5 + 30 - $topOffset, 125, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(170, $iline5 + 30 - $topOffset, 170, $iline7 + 30 - $topOffset + $tableHeightIncrease);
  
    $this->LineTo(230, $iline5 + 30 - $topOffset, 230, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(310, $iline5 + 30 - $topOffset, 310, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(380, $iline5 + 30 - $topOffset, 380, $iline7 + 30 - $topOffset + $tableHeightIncrease);
	  $this->LineTo(430, $iline5 + 30 - $topOffset, 430, $iline7 + 30 - $topOffset + $tableHeightIncrease);
	   

} else {
    // Original lines for other document types
    $this->LineTo(50, $iline5 + 30 - $topOffset, 50, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(98, $iline5 + 30 - $topOffset, 98, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(358, $iline5 + 30 - $topOffset, 358, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(385, $iline5 + 30 - $topOffset, 385, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(415, $iline5 + 30 - $topOffset, 415, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(450, $iline5 + 30 - $topOffset, 450, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(485, $iline5 + 30 - $topOffset, 485, $iline7 + 30 - $topOffset + $tableHeightIncrease);
    $this->LineTo(515, $iline5 + 30 - $topOffset, 515, $iline7 + 30 - $topOffset + $tableHeightIncrease);
}

			
		
		


		// Company Logo
		// Define the top margin
$topMargin = 20; // Adjust as needed

// Company Logo
$logo = company_path() . "/images/" . $this->company['coy_logo'];
if ($this->company['coy_logo'] != '' && file_exists($logo))
{
    // Calculate the coordinates for placing the logo
    $logoWidth = 90; // Adjust the width of the logo as needed
    $logoHeight = 90; // Adjust the height of the logo as needed
    $logoX = ($right + $ccol-30) / 2 - $logoWidth / 2; // Center the logo horizontally
    $logoY = $this->row - $topMargin - 45; // Position the logo with top margin

    $this->NewLine();
    $this->AddImage($logo, $logoX, $logoY, 0, $logoHeight); // Adjust the X and Y coordinates and height for the logo
}

		$this->NewLine();
		$this->fontSize += 4;
		$this->Font('bold');
			$logo = company_path() . "/images/name6.png" ;
if ($this->company['coy_logo'] != '' && file_exists($logo))
{
    // Calculate the coordinates for placing the logo
    $logoWidth = 135; // Adjust the width of the logo as needed
    $logoHeight = 80; // Adjust the height of the logo as needed
   $logoX = $ccol-15; // Center the logo horizontally
    $logoY = $this->row - $topMargin -6; // Position the logo with top margin

    $this->NewLine();
    $this->AddImage($logo, $logoX, $logoY, 0, $logoHeight); // Adjust the X and Y coordinates and height for the logo
}
		$this->Font();
		$this->fontSize -= 4;
		// Document title
		
		$this->NewLine();
		$this->SetTextColor(0, 0, 0);
		$adrline = $this->row;

		// Company data
		
		$this->Font();
		$this->row = $adrline;
		
		// Define the coordinates and size parameters
$imageX = $mcol + 80; // X-coordinate
$imageY = $yCoordinate ; // Adjust the Y-coordinate to add more space on top
$imageWidth = 200; // Adjust the width of the image
$imageHeight = 85; // Adjust the height of the image

// Path to your image file
$imagePath = company_path() . "/images/company_name.png";

// Display the image at the specified coordinates and size
$this->Image($imagePath, $imageX, $imageY, $imageWidth, $imageHeight);

// Add more space after displaying the image


		$this->NewLine(2);
	
		if ($this->pageNumber > 1)
			$this->Text($mcol + 180, _("Page") . ' ' . $this->pageNumber);
		$this->row = $iline1 - $this->lineHeight +50;
		$this->fontSize += 1;
	    $this->font('bold');
		$this->Text($ccol, $Addr1['title'], $icol);
		$this->Text($mcol, $Addr2['title']);
		$this->fontSize -= 1;



// address1
$maxLineLength = 25; 
		$temp = $this->row = $this->row - $this->lineHeight -3 ;
	
		if (strlen($Addr1['name']) > $maxLineLength) {
    // Split the company name at the last space before the maximum length
    $splitPos = strrpos(substr($Addr1['name'], 0, $maxLineLength), ' ');
    $nameLine1 = substr($Addr1['name'], 0, $splitPos);
    $nameLine2 = substr($Addr1['name'], $splitPos + 1);
    
    // Display the split company name in two lines
    $this->Text($ccol, $nameLine1);
    $this->NewLine();
    $this->Text($ccol, $nameLine2);
} else {
    // Display the company name in a single line if it's not too long
    $this->Text($ccol, $Addr1['name']);
}
if($doctype != ST_PURCHORDER) {
		$this->NewLine();
		// Check if the company name needs to be split into two lines
if (strlen($Addr1['company']) > $maxLineLength) {
    // Split the company name at the last space before the maximum length
    $splitPos = strrpos(substr($Addr1['company'], 0, $maxLineLength), ' ');
    $companyLine1 = substr($Addr1['company'], 0, $splitPos);
    $companyLine2 = substr($Addr1['company'], $splitPos + 1);
    
    // Display the split company name in two lines
    $this->Text($ccol, $companyLine1);
    $this->NewLine();
    $this->Text($ccol, $companyLine2);
} else {
    // Display the company name in a single line if it's not too long
    $this->Text($ccol, $Addr1['company']);
}
}
    $this->NewLine();
		$this->TextWrapLines($ccol, $icol - $ccol, $Addr1['address']);
			
		if($doctype != ST_PURCHORDER) {
		$this->Text($ccol, $Addr1['email']); // Display customer email
       $this->NewLine();
		$this->Text($ccol, $Addr1['phone']); // Display customer phone number
       $this->NewLine();
		}
	   $this->Text($ccol, $Addr1['tax']); // Display customer phone number
       $this->NewLine();
	   
        
   if($doctype == ST_PURCHORDER) {
		$this->row=$this->row = $this->row - $this->lineHeight + 45;
   }
   else{
	$this->row=$this->row = $this->row - $this->lineHeight + 80;
   }	
		$this->fontSize += 7;
		$this->Font('bold');
		$this->TextWrap($mcol-70, $this->row, $this->pageWidth - $this->rightMargin - $mcol - 20, $this->title, 'left');
		$this->TextWrap($mcol-70, $this->row, $this->pageWidth - $this->rightMargin - $mcol - 20,"______________", 'left');
		$this->NewLine(1.5);
		$this->Font('bold');
		$this->fontSize -= 4;

		$this->TextWrap($mcol-60, $this->row, $this->pageWidth - $this->rightMargin - $mcol - 20, _("   OM1100027765"), 'left');
		
		$this->Font();
		$this->fontSize -= 3;
// address2
	
      
		// Auxiliary document information
	 $this->row =$temp+10;
	
		$this->Text($mcol + 90, $this->formData['document_name']);
	
		$this->Text($mcol + 210, $this->formData['document_number']);
		$this->NewLine(1.5);
		
		
			
	 	$this->Text($mcol + 90, _("DATE"));
		
		$this->Text($mcol + 210, sql2date($this->formData['document_date']));
		$this->NewLine(1.5);
		

	if ($print_preparer)
		{
	
			$this->Text($mcol + 90, _("CREATED BY"));
			$preparer = trim($user['real_name']);
			if (empty($preparer)) $preparer = $user['user_id'];
			$this->Text($mcol + 210, $preparer);
		}	
	
		// Payment terms
		

		// Line headers
	
		$this->row = $iline5 - $this->lineHeight+95;
		
		$this->Font('bold');


		$count = count($this->headers);
		$this->cols[$count] = $right - 3;
		
		for ($i = 0; $i < $count; $i++)
 
		    $this->TextCol($i, $i + 1, $this->headers[$i], -2);
			
			
		$this->Font();

		// Footer
		
		
		$this->row = $iline7 - $this->lineHeight - 6 - 50;
 if ($this->formData['doctype'] != ST_PURCHORDER) {
// Path to your image file
$imagePath = company_path() . "/images/footer3.png";

// Calculate the coordinates and size for the image
$imageX = $ccol; // X-coordinate
$imageY = $this->row +600 ; // Y-coordinate
$imageWidth = 160; // Adjust the width of the image as needed
$imageHeight = 70; // Adjust the height of the image as needed

// Add the image to the PDF
if ($this->formData['doctype'] !=ST_STATEMENT ){
$this->Image($imagePath, $imageX, $imageY, $imageWidth, $imageHeight);
}
// Update the row position for the next content
$this->row -= $imageHeight; // Adjust as needed based on the image height

 }
		$this->Font();
		$temp = $iline6 - $this->lineHeight - 2;
 $this->row =($right + $ccol-570);
		$this->Font('bold');
	

		$this->Line($iline7 -75 );
		$this->NewLine(3.5);
		
		
		$this->Text($mcol - 280, _("Old Bazaar Business L.L.C"));
	 	$this->Text($mcol+100, _("RECIEVERS SIGNATURE"));
		
	