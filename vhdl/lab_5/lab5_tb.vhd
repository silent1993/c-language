--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:01:51 07/04/2014
-- Design Name:   
-- Module Name:   D:/vhdl/lab_5/lab5_tb.vhd
-- Project Name:  lab_5
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: lab5
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY lab5_tb IS
END lab5_tb;
 
ARCHITECTURE behavior OF lab5_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT lab5
    PORT(
         DATA : IN  std_logic;
         CLK : IN  std_logic;
         CSN : IN  std_logic;
         WRN : IN  std_logic;
         RDN : IN  std_logic;
         A : IN  std_logic_vector(1 downto 0);
         INTN : OUT  std_logic;
         D : INOUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal DATA : std_logic := '0';
   signal CLK : std_logic := '0';
   signal CSN : std_logic := '0';
   signal WRN : std_logic := '0';
   signal RDN : std_logic := '0';
   signal A : std_logic_vector(1 downto 0) := (others => '0');

	--BiDirs
   signal D : std_logic_vector(7 downto 0);

 	--Outputs
   signal INTN : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: lab5 PORT MAP (
          DATA => DATA,
          CLK => CLK,
          CSN => CSN,
          WRN => WRN,
          RDN => RDN,
          A => A,
          INTN => INTN,
          D => D
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;
--start		
		 DATA <='1';
		 CSN <='0';
		 WRN <='0';
		 RDN<='0';
		 A <="00";
		  wait for CLK_period;
		  DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";
		  wait for CLK_period;
		   DATA <='1';
		 CSN <='0';
		 WRN <='0';
		 RDN<='0';
		 A <="01";
		  wait for CLK_period;
		   DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="01";
		  wait for CLK_period;
		 DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='0';
		 A <="10";
		 wait for CLK_period;
	    DATA <='1';
		 CSN <='0';
		 WRN <='0';
		 RDN<='0';
		 A <="10";
		 wait for CLK_period;
		 DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='0';
		 A <="11";
		  wait for CLK_period;
		  DATA <='1';
		 CSN <='0';
		 WRN <='0';
		 RDN<='0';
		 A <="11";
	
--data1

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";
      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";
--enddata1
		wait for CLK_period;
		 
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='0';
		 A <="00";
		 wait for CLK_period;
		 
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";
		  wait for CLK_period;
		 
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='0';
		 A <="01";

--data2teste
		wait for CLK_period;
       DATA <='1';
		 CSN <='0';
		 WRN <='0';
		 RDN<='0';
		 A <="00";
		  wait for CLK_period;
		   DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='0';
		 A <="01";
		 wait for CLK_period;
		   DATA <='1';
		 CSN <='0';
		 WRN <='0';
		 RDN<='0';
		 A <="01";
		 
--start
     wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";
      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";
--end	
	wait for CLK_period;
		 
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='0';
		 A <="00";
		 wait for CLK_period;
		 
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";
		  wait for CLK_period;
		 
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='0';
		 A <="01";
--data3OVER	
		wait for CLK_period;
		   DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";
		 wait for CLK_period;
		   DATA <='1';
		 CSN <='0';
		 WRN <='0';
		 RDN<='1';
		 A <="00";
		  wait for CLK_period;
		   DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="10";
		 wait for CLK_period;
		   DATA <='1';
		 CSN <='0';
		 WRN <='0';
		 RDN<='1';
		 A <="10";
		  wait for CLK_period;
		   DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="01";
		 wait for CLK_period;
		   DATA <='1';
		 CSN <='0';
		 WRN <='0';
		 RDN<='1';
		 A <="01";
		 

		 
--start
 wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";
      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";

      wait for CLK_period;
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";
		  wait for CLK_period;
		DATA <='0';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="00";
		
--end
	wait for CLK_period;
		 
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='0';
		 A <="01";
		 wait for CLK_period;
		 
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='1';
		 A <="01";
		  wait for CLK_period;
		 
		DATA <='1';
		 CSN <='0';
		 WRN <='1';
		 RDN<='0';
		 A <="00";
      
	
		 
      -- insert stimulus here 

      wait;
   end process;

END;
