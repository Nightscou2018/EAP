---
title: PumpCommunication
author: Rick van Schijndel
---

# Abstract

This document describes the responsibilities of the pump communication component and classes within.

# Overview

The pump communication component is responsible for handling the connection to the pump and to the pump and sending and receiving packets to it.

It makes sure packets to send and received are checked for validity, before someone else can do something with them.

# Protocol

The protocol part is responsible for pump-specific protocol knowledge. It will be able to decode the messages retrieved from the pump and convert them into a format people and other code can easily use and comprehend. It will talk to the pump with the help of packets  to get data and then interpret it and make some useful information out of the raw data.

## CarelinkTranslation

The carelink translation piece is responsible for decoding different packets and filling a data-specific model for them.

# Raw

The raw namespace contains all the code used to deal with raw pump communication. It exposes packets to other places, which can use the raw data in the packets to reason about them.

It also is responsible for making sure packets to send get a CRC added and packets to receive are checked for validity, and dropped if they are not valid.

## RadioInterface

Defines how to talk with the radio class. Some energy-saving options are also required from the radio, because battery life/low energy usage is important to us. If any of the functions fail, they will return a non-zero error code to show the user something is wrong.

## Radio

The radio abstracts communication with the radio. It will have functions to help achieve maximum battery life. It uses the packet interface to receive and send packets.

## RequestPacket

The request class is responsible for storing data for a pump request. It's also responsible for appending a CRC to a request packet. It also contains a field to set the maximum retries a pump should do before giving up sending the packet. The max retries should be 0 if we only want the packet to be tried once.

## ResponsePacket

The response packet is responsible for storing the data from a pump response. It's also responsible for validating a packet using the CRC in the packet.

## PumpConfiguration

Keeps track of settings for the pump and which might be different between different users.
