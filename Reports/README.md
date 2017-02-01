# Reports
NJ Division of taxation reports from Easybiz software PDF files. Copy and paste the pdf into a .txt and the work is largely done for schedule G sales. The report should come from Reports>Sales>Inventory Sales Report. Although subcategory reports are much more common and what you probably default to, I suggest using the category report rather than item or subcategory because subcategories are not required and if an item was inadvertantly input without a subcategory then that item will still be included in this report. Output needs to be updated for several brands. Any company for which most items will fall under the schedule G should just add the first word of non-cigarette items in the big if statement
    
Issues:    
    
Brand names are not broken down properly for brands with long names (because it's space delimited) or brands with the manufacturer's name in the brand name.     

Examples include:     
"B & H" outputs just "B", "L & M" outputs just "L", and "VIR SLIMS" outputs "VIR".    
Also "NAT SHERMAN" needs to not have the manufacturer in every name 
