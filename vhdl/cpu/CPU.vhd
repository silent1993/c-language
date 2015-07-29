----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:22:44 07/11/2014 
-- Design Name: 
-- Module Name:    CPU - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity CPU is
    Port ( RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           ABUS : out  STD_LOGIC_VECTOR (15 downto 0);
           DBUS : inout  STD_LOGIC_VECTOR (15 downto 0);
           nMREQ : out  STD_LOGIC;
           nRD : out  STD_LOGIC;
           nWR : out  STD_LOGIC;
           nBHE : out  STD_LOGIC;
           nBLE : out  STD_LOGIC;
           IODB : inout  STD_LOGIC_VECTOR (7 downto 0);
			  nPREQ : out  STD_LOGIC;
           nPRD : out  STD_LOGIC;
           nPWR : out  STD_LOGIC);
end CPU;

architecture Behavioral of CPU is
component visit_M 
    Port ( CS2 : in  STD_LOGIC;
           datain : in  STD_LOGIC_VECTOR (7 downto 0);--in:LDA,OUT 
			  dataout:out STD_LOGIC_VECTOR (7 downto 0);--out:STA,IN
           ALUOUT : in  STD_LOGIC_VECTOR (7 downto 0);
           OP : in  STD_LOGIC_VECTOR (4 downto 0);
           Rtemp : out  STD_LOGIC_VECTOR (7 downto 0);
           IODB : inout  STD_LOGIC_VECTOR (7 downto 0);
			   nPREQ : out  STD_LOGIC;
           nPRD : out  STD_LOGIC;
           nPWR : out  STD_LOGIC);
	end component;
	component alu 
    Port ( CS1 : in  STD_LOGIC;
           Raddr : in  STD_LOGIC_VECTOR (2 downto 0);
           Rupdate : in  STD_LOGIC;
			  Atemp: out STD_LOGIC_VECTOR(7 downto 0);
           Rdata : in  STD_LOGIC_VECTOR (7 downto 0);
           IR : in  STD_LOGIC_VECTOR (15 downto 0);
           OP : out  STD_LOGIC_VECTOR (4 downto 0);
           ALUOUT : out  STD_LOGIC_VECTOR (7 downto 0);
           ADDR : out  STD_LOGIC_VECTOR (15 downto 0));
		end component;
	component back 
    Port ( CS3 : in  STD_LOGIC;
           PC : in  STD_LOGIC_VECTOR (15 downto 0);
           IR : in  STD_LOGIC_VECTOR (15 downto 0);
			  adir:in STD_LOGIC_VECTOR (15 downto 0);
			  Rtemp:in  STD_LOGIC_VECTOR (7 downto 0);
			  Atemp:in  STD_LOGIC_VECTOR (7 downto 0);
           ALUOUT : in  STD_LOGIC_VECTOR (7 downto 0);
           PCupdate : out  STD_LOGIC;
           PCnew : out  STD_LOGIC_VECTOR (15 downto 0);
           Rupdate : out  STD_LOGIC;
           Raddr : out  STD_LOGIC_VECTOR (2 downto 0);
           Rdata : out  STD_LOGIC_VECTOR (7 downto 0));
	end component;
	component number1 
    Port ( CLK : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           T1 : out  STD_LOGIC;
           T2 : out  STD_LOGIC;
           T3 : out  STD_LOGIC;
           T4 : out  STD_LOGIC);
		end component;
	component  ctrl_M 
    Port ( PC : in  STD_LOGIC_VECTOR (15 downto 0);
           ADDR : in  STD_LOGIC_VECTOR (15 downto 0);
           OP : in  STD_LOGIC_VECTOR (4 downto 0);
           datain : in  STD_LOGIC_VECTOR (7 downto 0);
			  CS0: in STD_LOGIC;
			  CS2: in STD_LOGIC;
           MADDR : out  STD_LOGIC_VECTOR (7 downto 0);
           MPC : out  STD_LOGIC_VECTOR (15 downto 0);
           DBUS : inout  STD_LOGIC_VECTOR (15 downto 0);
           ABUS : out  STD_LOGIC_VECTOR (15 downto 0);
           nMREQ : out  STD_LOGIC;
           nRD : out  STD_LOGIC;
           nWR : out  STD_LOGIC;
           nBHE : out  STD_LOGIC;
           nBLE : out  STD_LOGIC);
		end component;
		component quzhi 
    Port ( PCupdate : in  STD_LOGIC;
           PCnew : in  STD_LOGIC_VECTOR (15 downto 0);
           CS0 : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           MPC : in  STD_LOGIC_VECTOR (15 downto 0);
           IR : out  STD_LOGIC_VECTOR (15 downto 0);
           PC : out  STD_LOGIC_VECTOR (15 downto 0));
		end component;
		signal T1,T2,T3,T4,PCupdate,Rupdate: STD_LOGIC;
		signal datain,dataout,Rdata,Rtemp,Atemp,ALUOUT:STD_LOGIC_VECTOR (7 downto 0);
		signal PC,IR,ADDR,PCnew,MPC:STD_LOGIC_VECTOR (15 downto 0);
		signal OP:STD_LOGIC_VECTOR(4 downto 0);
	 signal  Raddr:STD_LOGIC_VECTOR (2 downto 0);
		 
begin
element1:component number1 port map(CLK,RST,T1,T2,T3,T4);
element2: component quzhi port map(PCupdate,PCnew,T1,Rst,MPC,IR,PC);
element3: component alu port map(T2,Raddr,Rupdate,Atemp,Rdata,IR,OP,ALUOUT,ADDR);
element4:component visit_M port map(T3,datain,dataout,ALUOUT,OP,Rtemp,IODB,nPREQ,nPRD,nPWR);
element5:component back port map(T4,PC,IR,ADDR,Rtemp,Atemp,ALUOUT,PCupdate,PCnew,Rupdate,Raddr,Rdata);
element6:component ctrl_M port map(PC,ADDR,OP,dataout,T1,T3,datain,MPC,DBUS,ABUS,nMREQ,nRD,nWR,nBHE,nBLE);
end Behavioral;

