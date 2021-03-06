cmake_minimum_required(VERSION 3.9)

add_library(mp4parse STATIC "")

include_directories("${CMAKE_CURRENT_LIST_DIR}/include")

target_sources(mp4parse
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/MP4.Atom.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.BXML.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.BinaryStream.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.CO64.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.CPRT.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.CTTS.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.ContainerAtom.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.DREF.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.DataAtom.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.ELST.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.FREE.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.FRMA.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.FTYP.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.File.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.FullBox.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.HDLR.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.HMHD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.IINF.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.ILOC.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.IMIF.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.IPMC.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.MDAT.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.MDHD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.MEHD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.MFHD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.MFRO.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.MVHD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.PADB.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.PDIN.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.PITM.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.Parser.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.SBGP.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.SCHI.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.SCHM.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.SDTP.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.SGPD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.SMHD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.STCO.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.STDP.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.STSC.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.STSD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.STSH.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.STSS.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.STSZ.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.STTS.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.STZ2.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.SUBS.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.TFHD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.TFRA.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.TKHD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.TREF.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.TREX.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.TRUN.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.UDTA.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.UnknownAtom.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.VMHD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MP4.XML.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mp4parse.cpp
)

install(TARGETS mp4parse ARCHIVE DESTINATION lib/)
install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/ DESTINATION include/mp4parse FILES_MATCHING PATTERN "*.h")
