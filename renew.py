import os, codecs, sys

with codecs.open("001_Two Sum/001_Two Sum.vcxproj", "r", "utf_8_sig") as f:
	std_vcxproj = f.readlines()
with codecs.open("%s/%s.vcxproj" % (sys.argv[1], sys.argv[1]), "r", "utf_8_sig") as f:
	vcxproj = f.readlines()
with codecs.open("%s/%s.vcxproj" % (sys.argv[1], sys.argv[1]), "w", "utf_8_sig") as f:
	std_vcxproj[22] = vcxproj[22]
	std_vcxproj[24] = vcxproj[24]
	std_vcxproj[149] = vcxproj[153]
	f.writelines(std_vcxproj)

with codecs.open("%s/%s.vcxproj.filters" % (sys.argv[1], sys.argv[1]), "r", "utf_8_sig") as f:
	filters = f.readlines()
with codecs.open("%s/%s.vcxproj.filters" % (sys.argv[1], sys.argv[1]), "w", "utf_8_sig") as f:
	f.writelines(filters[:16])
	f.write(filters[24])
	f.writelines(filters[28:])

os.remove("%s/stdafx.cpp" % sys.argv[1])
os.remove("%s/stdafx.h" % sys.argv[1])
os.remove("%s/targetver.h" % sys.argv[1])
