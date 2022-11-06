<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
	<html>
		<head>
			<title>Movies Collections</title>
			<link rel="stylesheet" href="./1000movies.css" type="text/css"/>
		</head>
		<body>
			<h1>My Movies:</h1>
			<table border="1">
				<tr bgcolor="#fca903">
					<th>Id</th>
					<th width = "250px">Title</th>
					<th>Time</th>
					<th width = "75px">Status</th>
					<th width = "150px">Vote</th>
					<th>RunTime</th>
					<th>Certif</th>
					<th>Budget</th>
					<th width = "150px">Summary</th>
					<th>Genres</th>
					<th>Directors</th>
					<th>Actors</th>
				</tr>
				<xsl:for-each select="Films/Film">
					<tr>
						<td><xsl:value-of select="@Id"/></td>
						<td><xsl:value-of select="Title"/></td>
						<td><xsl:value-of select="Time/@Day"/>/<xsl:value-of select="Time/@Month"/>/<xsl:value-of select="Time/@Year"/></td>
						<td><xsl:value-of select="Status"/></td>
						<td><span class="Vote"><span>Vote: <xsl:value-of select="Vote/@Count"/></span> | <span><xsl:value-of select="Vote"/>⭐</span></span></td>
						<td><xsl:value-of select="RunTime"/></td>
						<td><xsl:value-of select="Certification"/></td>
						<td><xsl:value-of select="Budget"/></td>
						<td><div class="Tag"><xsl:value-of select="Tag"/></div></td>

						<td style="resize:both;">
							<div class="Genre">
							<table class="secondary">	
								<tbody>							
									<xsl:for-each select="Genres/Genre">
									<tr>
										<td>(<xsl:value-of select="@Id"></xsl:value-of>)</td>
										<td><xsl:value-of select="@Label"></xsl:value-of></td>
									</tr>
									</xsl:for-each>	
								</tbody>
							</table>
							</div>
						</td>


						<td style="resize:both;">
							<div class="Genre">
							<table class="secondary">	
								<tbody>							
									<xsl:for-each select="Directors/Director">
									<tr>
										<td>(<xsl:value-of select="@Id"></xsl:value-of>)</td>
										<td><xsl:value-of select="@Name"></xsl:value-of></td>
									</tr>
									</xsl:for-each>	
								</tbody>
							</table>
							</div>
						</td>

						<td style="resize:both;">
							<div class="Genre">
							<table class="secondary">	
								<tbody>							
									<xsl:for-each select="Actors/Actor">
									<tr>
										<td>(<xsl:value-of select="@Id"></xsl:value-of>)</td>
										<td><xsl:value-of select="@ActName"></xsl:value-of></td>
										<td>Joue: <xsl:value-of select="@CharName"></xsl:value-of></td>
									</tr>
									</xsl:for-each>	
								</tbody>
							</table>
							</div>
						</td>

					</tr>
				</xsl:for-each>
			</table>
		</body>
	</html>

	</xsl:template>
</xsl:stylesheet>