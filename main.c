#include <assert.h>
#include <libmxml4/mxml.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static const char* xml =
    "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
    "\n"
    "<!--\n"
    "FILE INFORMATION\n"
    "\n"
    "OMA Permanent Document\n"
    "   File: OMA-SUP-XML_0-V1_2-20201110-A.xml\n"
    "   Path: http://www.openmobilealliance.org/release/ObjLwM2M_Security/\n"
    "\n"
    "OMNA LwM2M Registry\n"
    "   Path: https://github.com/OpenMobileAlliance/lwm2m-registry\n"
    "   Name: 0.xml\n"
    "\n"
    "NORMATIVE INFORMATION\n"
    "\n"
    "  Information about this file can be found in the latest revision of\n"
    "\n"
    "  OMA-TS-LightweightM2M_Core-V1_2\n"
    "\n"
    "  This is available at http://www.openmobilealliance.org/release/LightweightM2M/\n"
    "\n"
    "  Send comments to https://github.com/OpenMobileAlliance/OMA_LwM2M_for_Developers/issues\n"
    "\n"
    "LEGAL DISCLAIMER\n"
    "\n"
    "  Copyright 2020 Open Mobile Alliance.\n"
    "\n"
    "  Redistribution and use in source and binary forms, with or without\n"
    "  modification, are permitted provided that the following conditions\n"
    "  are met:\n"
    "\n"
    "  1. Redistributions of source code must retain the above copyright\n"
    "  notice, this list of conditions and the following disclaimer.\n"
    "  2. Redistributions in binary form must reproduce the above copyright\n"
    "  notice, this list of conditions and the following disclaimer in the\n"
    "  documentation and/or other materials provided with the distribution.\n"
    "  3. Neither the name of the copyright holder nor the names of its\n"
    "  contributors may be used to endorse or promote products derived\n"
    "  from this software without specific prior written permission.\n"
    "\n"
    "  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS\n"
    "  \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT\n"
    "  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS\n"
    "  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE\n"
    "  COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,\n"
    "  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,\n"
    "  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;\n"
    "  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER\n"
    "  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT\n"
    "  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN\n"
    "  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE\n"
    "  POSSIBILITY OF SUCH DAMAGE.\n"
    "\n"
    "  The above license is used as a license under copyright only.  Please\n"
    "  reference the OMA IPR Policy for patent licensing terms:\n"
    "  https://www.omaspecworks.org/about/intellectual-property-rights/\n"
    "\n"
    "-->\n"
    "\n"
    "<LWM2M xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:noNamespaceSchemaLocation=\"http://www.openmobilealliance.org/tech/profiles/LWM2M-v1_1.xsd\">\n"
    "  <Object ObjectType=\"MODefinition\">\n"
    "\t\t<Name>LWM2M Security</Name>\n"
    "\t\t<Description1><![CDATA[This LwM2M Object provides the keying material of a LwM2M Client appropriate to access a specified LwM2M Server. One Object Instance SHOULD address a LwM2M Bootstrap-Server.\n"
    "These LwM2M Object Resources MUST only be changed by a LwM2M Bootstrap-Server or Bootstrap from Smartcard and MUST NOT be accessible by any other LwM2M Server.]]></Description1>\n"
    "\t\t<ObjectID>0</ObjectID>\n"
    "\t\t<ObjectURN>urn:oma:lwm2m:oma:0:1.2</ObjectURN>\n"
    "\t  \t<LWM2MVersion>1.1</LWM2MVersion>\n"
    "\t\t<ObjectVersion>1.2</ObjectVersion>\n"
    "\t\t<MultipleInstances>Multiple</MultipleInstances>\n"
    "\t\t<Mandatory>Mandatory</Mandatory>\n"
    "\t\t<Resources>\n"
    "\t\t\t<Item ID=\"0\">\n"
    "\t\t\t\t<Name>LWM2M  Server URI</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Mandatory</Mandatory>\n"
    "\t\t\t\t<Type>String</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..255</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[Uniquely identifies the LwM2M Server or LwM2M Bootstrap-Server. The format of the CoAP URI is defined in Section 6 of RFC 7252.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"1\">\n"
    "\t\t\t\t<Name>Bootstrap-Server</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Mandatory</Mandatory>\n"
    "\t\t\t\t<Type>Boolean</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[Determines if the current instance concerns a LwM2M Bootstrap-Server (true) or a standard LwM2M Server (false)]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"2\">\n"
    "\t\t\t\t<Name>Security Mode</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Mandatory</Mandatory>\n"
    "\t\t\t\t<Type>Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..4</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[Determines which security mode is used\n"
    "0: Pre-Shared Key mode\n"
    "1: Raw Public Key mode\n"
    "2: Certificate mode\n"
    "3: NoSec mode\n"
    "4: Certificate mode with EST]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"3\">\n"
    "\t\t\t\t<Name>Public Key or Identity</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Mandatory</Mandatory>\n"
    "\t\t\t\t<Type>Opaque</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[Stores the LwM2M Client's certificate, public key (RPK mode) or PSK Identity (PSK mode).]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"4\">\n"
    "\t\t\t\t<Name>Server Public Key</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Mandatory</Mandatory>\n"
    "\t\t\t\t<Type>Opaque</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[Stores the LwM2M Server's, respectively LwM2M Bootstrap-Server's, certificate, public key (RPK mode) or trust anchor. The Certificate Mode Resource determines the content of this resource.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"5\">\n"
    "\t\t\t\t<Name>Secret Key</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Mandatory</Mandatory>\n"
    "\t\t\t\t<Type>Opaque</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[Stores the secret key (PSK mode) or private key (RPK or certificate mode).]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"6\">\n"
    "\t\t\t\t<Name>SMS Security Mode</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..255</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[Determines which SMS security mode is used: \n"
    "0: Reserved for future use\n"
    "1: DTLS mode (Device terminated) PSK mode assumed\n"
    "2: Secure Packet Structure mode (Smartcard terminated)\n"
    "3: NoSec mode\n"
    "4: Reserved mode (DTLS mode with multiplexing Security Association support)\n"
    "5-203 : Reserved for future use\n"
    "204-255: Proprietary modes]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"7\">\n"
    "\t\t\t\t<Name>SMS Binding Key Parameters</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Opaque</Type>\n"
    "\t\t\t\t<RangeEnumeration>6</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[Stores the KIc, KID, SPI and TAR.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"8\">\n"
    "\t\t\t\t<Name>SMS Binding Secret Key(s)</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Opaque</Type>\n"
    "\t\t\t\t<RangeEnumeration>16,32,48</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[Stores the values of the key(s) for the SMS binding.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"9\">\n"
    "\t\t\t\t<Name>LwM2M Server SMS Number</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>String</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[MSISDN used by the LwM2M Client to send messages to the LwM2M Server via the SMS binding.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"10\">\n"
    "\t\t\t\t<Name>Short Server ID</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>1..65534</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[This identifier uniquely identifies each LwM2M Server configured for the LwM2M Client.\n"
    "This Resource MUST be set when the Bootstrap-Server Resource has a value of 'false'. \n"
    "The values ID:0 and ID:65535 values MUST NOT be used for identifying the LwM2M Server.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"11\">\n"
    "\t\t\t\t<Name>Client Hold Off Time</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units>s</Units>\n"
    "\t\t\t\t<Description><![CDATA[The number of seconds to wait before initiating a Client Initiated Bootstrap once the LwM2M Client has determined it should initiate this bootstrap mode.\n"
    "In case client initiated bootstrap is supported by the LwM2M Client, this resource MUST be supported. This information is relevant for use with a Bootstrap-Server only.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"12\">\n"
    "\t\t\t\t<Name>Bootstrap-Server Account Timeout</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units>s</Units>\n"
    "\t\t\t\t<Description><![CDATA[The LwM2M Client MUST purge the LwM2M Bootstrap-Server Account after the timeout value given by this resource. The lowest timeout value is 1.\n"
    "If the value is set to 0, or if this resource is not instantiated, the Bootstrap-Server Account lifetime is infinite.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"13\">\n"
    "\t\t\t\t<Name>Matching Type</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Unsigned Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..3</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[The Matching Type Resource specifies how the certificate or raw public key in in the Server Public Key is presented. Four values are currently defined:\n"
    "                0: Exact match. This is the default value and also corresponds to the functionality of LwM2M v1.0. Hence, if this resource is not present then the content of the Server Public Key Resource corresponds to this value.\n"
    "                1: SHA-256 hash [RFC6234]\n"
    "                2: SHA-384 hash [RFC6234]\n"
    "                3: SHA-512 hash [RFC6234]]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"14\">\n"
    "\t\t\t\t<Name>SNI</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>String</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[This resource holds the value of the Server Name Indication (SNI) value to be used during the TLS handshake. When this resource is present then the LwM2M Server URI acts as the address of the service while the SNI value is used for matching a presented certificate, or PSK identity.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"15\">\n"
    "\t\t\t\t<Name>Certificate Usage</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Unsigned Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..3</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[The Certificate Usage Resource specifies the semantic of the certificate or \n"
    "                raw public key stored in the Server Public Key Resource, which is used to match \n"
    "                the certificate presented in the TLS/DTLS handshake. The currently defined values are \n"
    "                0 for \"CA constraint\", 1 for \"service certificate constraint\", 2 for \"trust anchor \n"
    "                assertion\", and 3 for \"domain-issued certificate\". When this resource is absent, \n"
    "                value (3) for domain issued certificate mode is assumed. More details about the \n"
    "                semantic of each value can be found in the security consideration section of the \n"
    "                LwM2M specification.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"16\">\n"
    "\t\t\t\t<Name>DTLS/TLS Ciphersuite</Name>\n"
    "        <Operations></Operations>\n"
    "        <MultipleInstances>Multiple</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Unsigned Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[When this resource is present it instructs the TLS/DTLS client to propose the indicated ciphersuite(s) in the ClientHello of the handshake. A ciphersuite is indicated as a 32-bit integer value. The IANA TLS ciphersuite registry is maintained at https://www.iana.org/assignments/tls-parameters/tls-parameters.xhtml. As an example, the TLS_PSK_WITH_AES_128_CCM_8 ciphersuite is represented with the following string \"0xC0,0xA8\". To form an integer value the two values are concatenated. In this example, the value is 0xc0a8 or 49320.]]></Description>\n"
    "            </Item>\n"
    "\t\t\t<Item ID=\"17\"><Name>OSCORE Security Mode</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Objlnk</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[If this resource is defined, it provides a link to the OSCORE Object Instance and OSCORE MUST be used by the LwM2M Client with the linked OSCORE Object Instance.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"18\">\n"
    "\t\t\t\t<Name>Groups To Use by Client</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Multiple</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Unsigned Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..65535</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[If this resource is defined, it indicates what groups the LwM2M Client should use with a LwM2M Server/LwM2M Bootstrap-Server (ordered from most preferred to least preferred). Resource instance 0 indicates the most preferred group. The values are taken from Section 4.2.7 of RFC 8446. An example is secp256r1 (0x0017).]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"19\">\n"
    "\t\t\t\t<Name>Signature Algorithms Supported by Server</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Multiple</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Unsigned Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..65535</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[If this resource is defined, it indicates what signature algorithms the LwM2M Server/LwM2M Bootstrap-Server supports. The values are taken from Section 4.2.3 of RFC 8446. An example is ecdsa_secp256r1_sha256(0x0403).]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t\t<Item ID=\"20\"><Name>Signature Algorithms To Use by Client</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Multiple</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Unsigned Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..65535</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[If this resource is defined, it indicates what signature algorithms the LwM2M Client should use with a LwM2M Server/LwM2M Bootstrap-Server (ordered from most preferred to least preferred). Resource instance 0 indicates the most preferred group. The values are taken from Section 4.2.3 of RFC 8446. An example is ecdsa_secp256r1_sha256(0x0403).]]></Description>\n"
    "\t\t\t</Item>            \n"
    "\t\t\t<Item ID=\"21\">\n"
    "\t\t\t\t<Name>Signature Algorithm Certs Supported by Server</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Multiple</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Unsigned Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..65535</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[If this resource is defined, it indicates what certificate-specific signature algorithms the the LwM2M Server/LwM2M Bootstrap-Server supports. The values are taken from Section 4.2.3 of RFC 8446. An example is ecdsa_secp256r1_sha256(0x0403).]]></Description>\n"
    "\t\t\t</Item>     \n"
    "\t\t\t<Item ID=\"22\">\n"
    "\t\t\t\t<Name>TLS 1.3 Features To Use by Client</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Unsigned Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..65535</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[If this resource is defined, it indicates which features the LwM2M Client should use with the respective LwM2M Server/LwM2M Bootstrap-Server. The bitmask values listed below are defined. A bit value of '0' means the feature should not be used. bit(0) - PSK Plain, bit(1) - 0-RTT, bit(2) - PSK with PFS, bit(3) - Certificate-based Authentication. Bit(4) to bit(31) are reserved.]]></Description>\n"
    "\t\t\t</Item>       \n"
    "\t\t\t<Item ID=\"23\">\n"
    "\t\t\t\t<Name>TLS Extensions Supported by Server</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Unsigned Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..65535</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[If this resource is defined, it indicates what extensions the LwM2M Server/LwM2M Bootstrap-Server supports in form of a bitmap.  The following values are defined: bit(0) - Server Name Indication (RFC 6066), bit (1) - Max Fragment Length (RFC 6066), bit (2) - Status Request (RFC 6066), bit (3) - Heartbeat (RFC 6520), bit (4) - Application Layer Protocol Negotiation (RFC 7301), bit (5) - Signed Certificate Timestamp (RFC 6962), bit (6) - Certificate Compression (draft-ietf-tls-certificate-compression), bit (7) - Record Size Limit (RFC 8449), bit (8) - Ticket Pinning (draft-ietf-tls-pinning-ticket), bit (9) - Certificate Authorities (RFC 8446), bit (10) - OID Filters (RFC 8446), bit (11) - Post Handshake Auth (RFC 8446), bit (12) - Connection ID (draft-ietf-tls-dtls-connection-id/draft-ietf-tls-dtls13). Bit(13) to bit(31) are reserved. ]]></Description>\n"
    "\t\t\t</Item>               \n"
    "\t\t\t<Item ID=\"24\">\n"
    "\t\t\t\t<Name>TLS Extensions To Use by Client</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Unsigned Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..65535</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[If this resource is defined, it indicates what extensions the LwM2M Client should use with the LwM2M Server/LwM2M Bootstrap-Server in form of a bitmap. The following values are defined: bit(0) - Server Name Indication (RFC 6066), bit (1) - Max Fragment Length (RFC 6066), bit (2) - Status Request (RFC 6066), bit (3) - Heartbeat (RFC 6520), bit (4) - Application Layer Protocol Negotiation (RFC 7301), bit (5) - Signed Certificate Timestamp (RFC 6962), bit (6) - Certificate Compression (draft-ietf-tls-certificate-compression), bit (7) - Record Size Limit (RFC 8449), bit (8) - Ticket Pinning (draft-ietf-tls-pinning-ticket), bit (9) - Certificate Authorities (RFC 8446), bit (10) - OID Filters (RFC 8446), bit (11) - Post Handshake Auth (RFC 8446), bit (12) - Connection ID (draft-ietf-tls-dtls-connection-id/draft-ietf-tls-dtls13). Bit(13) to bit(31) are reserved. ]]></Description>\n"
    "\t\t\t</Item>               \n"
    "\t\t\t<Item ID=\"25\">\n"
    "\t\t\t\t<Name>Secondary LwM2M Server URI</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Multiple</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>String</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..255</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[If this resource is present then the LwM2M Server URI in the Security Object, Resource ID 0, is augmented with information about further LwM2M Server URIs that can be used with the same security information found in the LwM2M Security Object. This is useful when a LwM2M Server is reachable via two different transport bindings (i.e. URIs). For example when the same server is reachable with two different URIs, such as a \"coaps\" and a \"coaps+tcp\" URI scheme.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"26\"><Name>MQTT Server</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Objlnk</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[If this resource is defined, it provides a link to a MQTT Server Object Instance, which offers additional configuration information for use with this MQTT server. This Resource is used only when the URI scheme in the LwM2M Server URI Resource indicates the use of MQTT.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"27\"><Name>LwM2M COSE Security</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Multiple</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Objlnk</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[If this resource is defined, it provides a links to LwM2M COSE Object Instances, which contain security-relevant configuration information for use with COSE.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"28\"><Name>RDS Destination Port</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..15</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[This resource provides the default RDS Destination Port Number (as defined in 3GPP TS 24.250) to use for contacting the LwM2M or Bootstrap Server when communicating through the SCEF across the Non-IP binding.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"29\"><Name>RDS Source Port</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>Integer</Type>\n"
    "\t\t\t\t<RangeEnumeration>0..15</RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[This resource provides the default RDS Source Port Number (as defined in 3GPP TS 24.250) to use for contacting the LwM2M or Bootstrap Server when communicating through the SCEF across the Non-IP binding.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t\t<Item ID=\"30\"><Name>RDS Application ID</Name>\n"
    "\t\t\t\t<Operations></Operations>\n"
    "\t\t\t\t<MultipleInstances>Single</MultipleInstances>\n"
    "\t\t\t\t<Mandatory>Optional</Mandatory>\n"
    "\t\t\t\t<Type>String</Type>\n"
    "\t\t\t\t<RangeEnumeration></RangeEnumeration>\n"
    "\t\t\t\t<Units></Units>\n"
    "\t\t\t\t<Description><![CDATA[This resource provides the Application ID (as defined in 3GPP TS 24.250) to use for querying the SCEF for the source and destination port numbers for contacting the LwM2M or Bootstrap Server when communicating through the SCEF across the Non-IP binding.]]></Description>\n"
    "\t\t\t</Item>\n"
    "\t\t</Resources>\n"
    "\t\t\t<Description2><![CDATA[]]></Description2>\n"
    "\t</Object>\n"
    "</LWM2M>";


int main (void ) {

  mxml_options_t *options = mxmlOptionsNew();
  mxmlOptionsSetTypeValue(options, MXML_TYPE_OPAQUE);

  mxml_node_t *root = mxmlLoadString(NULL, options, xml);
  assert(root);

  mxml_node_t * object = mxmlFindPath(root, "LWM2M/Object");
  assert(object);

  mxml_node_t  * object_name_element = mxmlFindElement(object, root, "Name", NULL, NULL, MXML_DESCEND_NONE);
  assert(object_name_element);
  const char *object_name;
  object_name = mxmlGetOpaque(object_name_element);
  printf("Object name: %s\n", object_name);

  mxml_node_t  * object_id_element = mxmlFindElement(object, root, "Name", NULL, NULL, MXML_DESCEND_NONE);
  int object_id = mxmlGetInteger(object_id_element);
  printf("Object id: %u\n", object_id);

  mxmlDelete(root);
  return 0;
}
