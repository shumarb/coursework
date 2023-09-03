<?xml version="1.0" encoding="UTF-8"?>
<!--
Source: https://stackoverflow.com/questions/17963067/how-to-get-maximum-value-under-same-node-in-xslt - How to find largest quantity in warehouse
for line 17
-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  <xsl:template match="/">
    <html>
      <body>
        <xsl:apply-templates select="child::warehouses/child::warehouse/child::address[child::country='Singapore' or country='Malaysia']/.."/>
      </body>
    </html>
  </xsl:template>

   <xsl:template match="warehouse">
        <h3> Warehouse: <xsl:value-of select="name"/></h3>
        <ul><xsl:apply-templates select = "child::items/child::item[not(../child::item/child::qty &gt; qty)]"/></ul>
        <!-- <h4> Country: <xsl:value-of select="child::address/child::country"/></h4> -->

    </xsl:template>
    <xsl:template match="item">
        <li>Item name: <xsl:value-of select = "child::name"/></li>
        <li>Item quantity: <xsl:value-of select = "child::qty"/></li>
    </xsl:template>
</xsl:stylesheet>
